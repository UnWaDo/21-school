#include "so_long.h"
#include "so_long_mlx.h"
#include "so_long_utils.h"

t_mlx	*start_mlx_win(t_pos w_h, char *title)
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
	mlx->win = mlx_new_window(mlx->mlx, w_h.x, w_h.y, title);
	if (mlx->win == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx);
		return (NULL);
	}
	mlx->images = NULL;
	return (mlx);
}

t_img	*create_new_image(t_mlx *mlx, t_pos w_h)
{
	t_img	*img;
	t_list	*lst;

	img = malloc(sizeof(*img));
	if (!img)
		return (NULL);
	img->w_h = w_h;
	img->img = mlx_new_image(mlx->mlx, w_h.x, w_h.y);
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
	img->addr = mlx_get_data_addr(img->img,
			&(img->bpp), &(img->line_len), &(img->endian));
	return (img);
}
