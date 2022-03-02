#include "so_long_mlx.h"

int	to_trgb(unsigned char t,
		unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_img *img, t_pos pos, int c)
{
	char	*dst;

	dst = img->addr + (pos.y * img->line_len + pos.x * (img->bpp / 8));
	((unsigned int *)dst)[0] = c;
}

void	put_rect(t_img *img, t_pos corner, t_pos w_h, int c)
{
	t_pos	till;

	till = (t_pos){.x = corner.x + w_h.x, .y = corner.y + w_h.y};
	while (corner.y < till.y)
	{
		while (corner.x < till.x)
		{
			put_pixel(img, corner, c);
			corner.x++;
		}
		corner.x -= w_h.x;
		corner.y++;
	}
}

void	fill_color(t_img *img, int c)
{
	put_rect(img, (t_pos){.x = 0, .y = 0}, img->w_h, c);
}
