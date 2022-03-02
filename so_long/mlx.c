#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"


# define WIDTH	640
# define HEIGHT	480
# define TITLE	"MiniLibX"
# define IMAGE	"cell.xpm"

# define O_INIT	0b0
# define O_GET	0b1
# define O_DEL	0b10

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	KEYCODE_ENTER = 65293,
	KEYCODE_ESCAPE = 65307,
	KEYCODE_W = 119,
	KEYCODE_A = 97,
	KEYCODE_S = 115,
	KEYCODE_D = 100,
	KEYCODE_SPACE = 32
};

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_list	*images;
}	t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_gen
{
	t_mlx	*mlx;
	int		x;
	int		y;
	int		fill_color;
	t_img	*hero_img;
	size_t	tick;
}	t_gen;

static void	clear_all(t_mlx *mlx)
{
	t_list	*el;
	t_list	*next;

	if (mlx == NULL || mlx->mlx == NULL)
		return ;
	el = mlx->images;
	while (el)
	{
		next = el->next;
		mlx_destroy_image(mlx->mlx, ((t_img *)(el->content))->img);
		free(el->content);
		free(el);
		el = next;
	}
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}

static int	close_ok(t_mlx *mlx)
{
	clear_all(mlx);
	exit(EXIT_SUCCESS);
}

static int	close_error(t_mlx *mlx)
{
	clear_all(mlx);
	perror("Error");
	exit(EXIT_FAILURE);
}

int	to_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_img *img, int x, int y, int c)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	((unsigned int *)dst)[0] = c;
}

void	put_rect(t_img *img, int x, int y, int width, int height, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			put_pixel(img, x + i, y + j, c);
			j++;
		}
		i++;
	}
}

void	fill_color(t_img *img, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->width)
	{
		j = 0;
		while (j < img->height)
		{
			put_pixel(img, i, j, c);
			j++;
		}
		i++;
	}
}

int	draw_view(t_gen *gen)
{
	fill_color(gen->hero_img, gen->fill_color);
	put_rect(gen->hero_img, gen->x, gen->y, 100, 100, to_trgb(0, 65, 130, 130));
	mlx_put_image_to_window(gen->mlx->mlx, gen->mlx->win, gen->hero_img->img, 0, 0);
	mlx_string_put(gen->mlx->mlx, gen->mlx->win, 10, HEIGHT - 10, to_trgb(0, 255, 255, 255), "Some sort of string");
	return (0);
}

int	key_released(int keycode, t_gen *gen)
{
	if (keycode == KEYCODE_ESCAPE)
		close_ok(gen->mlx);
	return (0);
}

int	key_pressed(int keycode, t_gen *gen)
{
	int	step;

	step = 10;
	if (keycode == KEYCODE_W)
		gen->y -= step;
	else if (keycode == KEYCODE_S)
		gen->y += step;
	else if (keycode == KEYCODE_A)
		gen->x -= step;
	else if (keycode == KEYCODE_D)
		gen->x += step;
	if (gen->x > WIDTH - 110 || gen->x < 10)
		gen->x = ((gen->x - 10) % (WIDTH - 110) + WIDTH - 110) % (WIDTH - 110) + 10;
	if (gen->y > HEIGHT - 110 || gen->y < 10)
		gen->y = ((gen->y - 10) % (HEIGHT - 110) + HEIGHT - 110) % (HEIGHT - 110) + 10;
	draw_view(gen);
	return (0);
}

t_mlx	*start_mlx_win(int width, int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
	if (mlx->win == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx);
		return (NULL);
	}
	mlx->images = NULL;
	mlx_hook(mlx->win, ON_DESTROY, 0, &close_ok, mlx);
	return (mlx);
}

t_img	*create_new_image(t_mlx *mlx, int width, int height)
{
	t_img	*img;
	t_list	*lst;

	img = malloc(sizeof(*img));
	if (!img)
		return (NULL);
	img->width = width;
	img->height = height;
	img->img = mlx_new_image(mlx->mlx, img->width, img->height);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	lst = ft_lstnew(img);
	if (!lst)
	{
		mlx_destroy_image(mlx->mlx, img->img);
		free(img);
		return (NULL);
	}
	ft_lstadd_back(&(mlx->images), lst);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len), &(img->endian));
	return (img);
}

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
# define TICK_LENGTH	1500

int	render_next(t_gen *gen)
{
	static size_t	time;

	time += 1;
	if (time % TICK_LENGTH == 0)
	{
		gen->tick += 1;
		gen->fill_color = to_trgb(0, time, time % 500, time % 1000);
		mlx_string_put(gen->mlx->mlx, gen->mlx->win, 0, HEIGHT, 0, "Some string");
		draw_view(gen);
	}
	return (0);
}

int	main(void)
{
	t_gen	gen;

	gen.tick = 0;
	gen.mlx = start_mlx_win(WIDTH, HEIGHT, TITLE);
	if (gen.mlx == NULL)
		close_error(gen.mlx);
	gen.hero_img = create_new_image(gen.mlx, WIDTH, HEIGHT);
	if (gen.hero_img == NULL)
		close_error(gen.mlx);
	gen.x = 10;
	gen.y = 10;
	gen.fill_color = to_trgb(0, 130, 130, 65);
	draw_view(&gen);
	mlx_hook(gen.mlx->win, 3, (1L<<1), &key_released, &gen);
	mlx_hook(gen.mlx->win, 2, (1L<<0), &key_pressed, &gen);
	mlx_loop_hook(gen.mlx->mlx, &render_next, &gen);
	mlx_loop(gen.mlx->mlx);
	return (0);
}