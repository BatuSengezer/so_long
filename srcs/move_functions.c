/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:28:08 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/23 20:37:20 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function that processes keyboard input into game
void	move_hook(mlx_key_data_t keydata, void *tmp)
{
	t_game	*game;

	game = (t_game *) tmp;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
}

void	pick_collectibles(t_game *game, int y, int x)
{
	size_t	collectible_i;

	collectible_i = 0;
	x = x * PIXELS + 16;
	y = y * PIXELS + 16;
	while (collectible_i < game->img->collectible->count)
	{
		if (game->img->collectible->instances[collectible_i].x == x
			&& game->img->collectible->instances[collectible_i].y == y)
		{
			game->img->collectible->instances[collectible_i].enabled = false;
		}
		collectible_i++;
	}
}
