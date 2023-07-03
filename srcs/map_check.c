# include "../includes/so_long.h"

// checks map for errors
void map_check(char *map_str)
{
    empty_map(map_str);
    empty_lines(map_str);
    wrong_content(map_str);
    wrong_shape(map_str);
    wrong_wall(map_str);
}

void empty_map(char *map)
{
    if (!map[0])
        write_error("Empty map!");
}

void empty_lines(char *map)
{
    size_t i;

    i = 0;
    while (map[i])
    {
        if (map[0] == '\n'|| (map[i] == '\n' && map[i + 1] == '\n'))
            write_error("Empty line in map!");
        i++;
    }
}

void wrong_content(char *map)
{
    int player;
    int collectibles;
    int exit;
    int i;

    player = 0;
	exit = 0;
	collectibles = 0;
	i = 0;
    while (map[i])
    {
        if (!(ft_strchr("PEC01\n", map[i])))
		    write_error("Invalid characters in map!");

        if (map[i] == 'P')
            player++;
        if (map[i] == 'C')
            collectibles++;
        if (map[i] == 'E')
            exit++;
        i++;
    }
    if (player != 1 || exit != 1 || collectibles < 1)
		write_error("Invalid map!");
}

void wrong_shape(char *map)
{
    size_t curr_line_len;
    size_t i;
    size_t len;

    curr_line_len = 0;
    i = 0;
    len = 0;
    while (map[i] != '\0')
    {
        while(map[i] != '\n' && map[i] != '\0')
        {
            i++;
            curr_line_len++;
        }
        if (len == 0)
            len = curr_line_len;
        else if (curr_line_len != len)
		    write_error("Wrong map shape!");
        curr_line_len = 0;
        if (map[i] == '\n')
            i++;
    }
}

// void wrong_wall(char *map)
// {
//     size_t i;
//     size_t width;
//     size_t map_len;

//     i = 0;
//     width = 0;
//     map_len = ft_strlen(map);
//     while (map[i] != '\0')
//     {
//         while (map[i] != '\n' && map[i] != '\0')
//         {
//             if (map[i] != '1')
//                 write_error("Wrong wall content");
//             i++;
//             width++;
//         }
//         i++;
//         while (i < map_len - width)
//         {
//             if (map[i] != '1' || map[i + width -1] != '1')
//                 write_error("Wrong wall content");
//             i = i + width + 1;
//         }
//         while (map[i] != '\0')
//         {
//             if (map[i] != '1')
//                 write_error("Wrong wall content");
//             i++;
//         }
//     }
// }

void wrong_wall(char *map)
{
    wall_check_horizontal(map);
    wall_check_vertical(map);
}

void wall_check_horizontal(char *map)
{
    size_t i;
    size_t width;
    size_t map_len;

    i = 0;
    width = 0;
    map_len = ft_strlen(map);
    while (map[i] != '\0')
    {
        while (map[i] != '\n' && map[i] != '\0')
        {
            if (map[i] != '1')
                write_error("Wrong wall content");
            i++;
            width++;
        }
        i = map_len - width;
        while (map[i] != '\0')
        {
            if (map[i] != '1')
                write_error("Wrong wall content");
            i++;
        }
    }
}

void wall_check_vertical(char *map)
{
    size_t i;
    size_t width;
    size_t map_len;

    i = 0;
    width = 0;
    map_len = ft_strlen(map);
    while (map[i] != '\0')
    {
        while (map[i] != '\n')
        {
            i++;
            width++;
        }
        i++;
        while (i < map_len - width -1)
        {
            if (map[i] != '1' || map[i + width -1] != '1')
                write_error("Wrong wall content");
            i = i + width + 1;
        }
        i = i + width;
    }
}
