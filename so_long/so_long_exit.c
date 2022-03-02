#include "libft.h"
#include "so_long_mlx.h"
#include "so_long.h"

static void	clear_mlx(t_mlx *mlx)
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

static void	clear_so_long(t_so_long *so_long)
{
	free(so_long->hero);
	delete_map(so_long->map);
	clear_mlx(so_long->mlx);
	free(so_long);
}

int	close_ok(t_so_long *so_long)
{
	clear_so_long(so_long);
	exit(EXIT_SUCCESS);
}

int	close_error(t_so_long *so_long)
{
	clear_so_long(so_long);
	perror("Error");
	exit(EXIT_FAILURE);
}
