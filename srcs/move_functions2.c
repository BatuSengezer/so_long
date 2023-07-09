/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:17:29 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/08 17:18:16 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->map_grid[game->player_y - 1][game->player_x] != '1'
		&& game->map_grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y - 1][game->player_x] == 'C')
		{
			pick_collectibles(game, game->player_y - 1, game->player_x);
			print_collectibles(game);
			game->map_grid[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	win_check(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->map_grid[game->player_y + 1][game->player_x] != '1'
		&& game->map_grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y + 1][game->player_x] == 'C')
		{
			pick_collectibles(game, game->player_y + 1, game->player_x);
			print_collectibles(game);
			game->map_grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	win_check(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x + 1] != '1'
		&& game->map_grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x + 1] == 'C')
		{
			pick_collectibles(game, game->player_y, game->player_x + 1);
			print_collectibles(game);
			game->map_grid[game->player_y][game->player_x + 1] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	win_check(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x - 1] != '1'
		&& game->map_grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x - 1] == 'C')
		{
			pick_collectibles(game, game->player_y, game->player_x - 1);
			print_collectibles(game);
			game->map_grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	win_check(game);
	return (game);
}

void	win_check(t_game *game)
{
	print_moves(game);
	if (game->collected == game->collectibles)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			write_error("Error during img to window!");
		game->map_grid[game->exit_y][game->exit_x] = '0';
		if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			ft_putendl_fd("Congratulations, you won!", 1);
		}
	}
}