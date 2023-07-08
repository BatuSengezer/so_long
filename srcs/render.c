/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:40:34 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/08 17:43:14 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	select_image(t_game *game, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (game->map_grid[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->img->bush,
				x * PIXELS, y * PIXELS) < 0)
			write_error("Error during img to window!"); 
	if (game->map_grid[y][x] == 'C')
		if (mlx_image_to_window(game->mlx, game->img->collectible,
				x * PIXELS + img_size / 2, y * PIXELS + img_size / 2) < 0)
			write_error("Error during img to window!"); 
	if (game->map_grid[y][x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			write_error("Error during img to window!");
	if (game->map_grid[y][x] == 'P')
		if (mlx_image_to_window(game->mlx, game->img->player,
				x * PIXELS, y * PIXELS) < 0)
			write_error("Error during img to window!");
	if (game->map_grid[y][x] == 'X')
		if (mlx_image_to_window(game->mlx, game->img->enemy,
				x * PIXELS, y * PIXELS) < 0)
			write_error("Error during img to window!");
}

void	render_map(t_game *game)
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
			select_image(game, y, x);
			x++;
		}
		y++;
	}
}
