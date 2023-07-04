# include "../includes/so_long.h"

// reads map file and joins lines to a string
char *read_map(char *map)
{
    char *line;
    char *map_str;
    int fd;

    fd = open(map, O_RDONLY);
    map_str = ft_calloc(1, 1);
    if (!map_str)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line)
        {
            map_str = ft_strjoin(map_str, line);
            free (line);
        }
        else
            break;
    }
    close (fd);
    return (map_str);
}

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

// gets x and y coordinates of player and exit
size_t get_position(t_game *game, char axis, char obj)
{
    size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map_grid[y][x] == obj)
			{
				if (axis == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
