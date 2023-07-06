# include "../include/so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->map_grid[game->player_y - 1][game->player_x] != '1'
		&& game->map_grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y - 1][game->player_x] == 'C')
		{
			remove_collectibles(game, game->player_y - 1, game->player_x);
			print_collectibless(game);
			game->map_grid[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->map_grid[game->player_y + 1][game->player_x] != '1'
		&& game->map_grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y + 1][game->player_x] == 'C')
		{
			remove_collectibles(game, game->player_y + 1, game->player_x);
			print_collectibless(game);
			game->map_grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x + 1] != '1'
		&& game->map_grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x + 1] == 'C')
		{
			remove_collectibles(game, game->player_y, game->player_x + 1);
			print_collectibless(game);
			game->map_grid[game->player_y][game->player_x + 1] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x - 1] != '1'
		&& game->map_grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x - 1] == 'C')
		{
			remove_collectibles(game, game->player_y, game->player_x - 1);
			print_collectibless(game);
			game->map_grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;
		game->steps += 1;
	}
	check_game_status(game);
	return (game);
}

void	remove_collectibles(t_game *game, int y, int x)
{
	int	collectible_i;

	collectible_i = 0;
	x = x * 64 + 16;
	y = y * 64 + 16;
	while (collectible_i < game->img->collectible->count)
	{
		if (game->img->collectible->instances[collectible_i].x == x
			&& game->img->collectible->instances[collectible_i].y == y)
		{
			game->img->collectible->instances[collectible_i].enabled = FALSE;
		}
		collectible_i++;
	}
}