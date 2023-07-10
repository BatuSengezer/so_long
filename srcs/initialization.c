/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:34:10 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/09 23:53:50 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// takes map as argument and initializes game
t_game	*init_game(char *map)
{
	char	*map_str;
	char	**map_arr;
	t_game	*game;
	size_t	i;

	i = 0;
	map_str = read_map(map);
	map_check(map_str);
	map_arr = ft_split(map_str, '\n');
	game = init_game_struct(map_arr);
	flood_fill(game);
	free(map_str);
	// free array causes memory leaks
	// while (map_arr[i])
	// {
	// 	free(map_arr[i]);
	// 	i++;
	// }
	// free(map_arr);
	return (game);
}

// fills game struct with map information
t_game	*init_game_struct(char **map_arr)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		write_error("Memory allocation error!");
	game->width = ft_strlen(map_arr[0]);
	game->height = count_rows(map_arr);
	game->map_grid = map_arr;
	game->steps = 0;
	game->collectibles = count_collectibles(game);
	game->player_x = get_position(game, 'x', 'P');
	game->player_y = get_position(game, 'y', 'P');
	game->exit_x = get_position(game, 'x', 'E');
	game->exit_y = get_position(game, 'y', 'E');
	return (game);
}

// initializes game images
t_img	*init_img_struct(mlx_t *mlx)
{
	t_img	*images;

	images = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!images)
		return (NULL);
	images = load_grass_texture(mlx, images);
	images = load_bush_texture(mlx, images);
	images = load_collectible_texture(mlx, images);
	images = load_player_texture(mlx, images);
	images = load_exit_closed(mlx, images);
	images = load_exit_open(mlx, images);
	images = load_enemy_texture(mlx, images);
	return (images);
}
