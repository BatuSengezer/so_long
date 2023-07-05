# include "../includes/so_long.h"

void	fill_background(t_game *game)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				write_error("Failed to put image to window");
			x++;
		}
		y++;
	}
}