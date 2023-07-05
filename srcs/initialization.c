# include "../includes/so_long.h"

// takes map as argument and initializes game
t_game	*game_init(char *map)
{
    char *map_str;
    char **map_arr;
    t_game *game;

    map_str = read_map(map);
    map_check(map_str);
    map_arr = ft_split(map_str, '\n');
    game = init_struct(map_arr);
    flood_fill(game);
    free(map_str);
    return (game);
}

// fills game struct with map information
t_game *init_struct(char **map_grid)
{
    t_game *game;

    game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
        write_error("Memory allocation problem!");
    game->width = ft_strlen(map_grid[0]);
    game->height = count_rows(map_grid);
	game->map_grid = map_grid;
	game->steps = 0;
	game->collectibles = count_collectibles(game);
	game->player_x = get_position(game, 'x', 'P');
	game->player_y = get_position(game, 'y', 'P');
    game->exit_x = get_position(game, 'x', 'E');
	game->exit_y = get_position(game, 'y', 'E');
    // load_player_textures(game);
    return (game);
}
