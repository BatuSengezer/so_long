# include "../includes/so_long.h"

// counts rows in the map
size_t count_rows(char **map_grid)
{
    size_t i;

    i = 0;
    while (map_grid[i])
        i++;
    return (i);
}

// counts collectibles on the map
size_t count_collectibles(t_game *game)
{
    size_t collectibles;
	size_t	x;
	size_t	y;

    collectibles = 0;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map_grid[y][x] == 'C')
                collectibles++;
            x++;
        }
        y++;
    }
    return(collectibles);
}
