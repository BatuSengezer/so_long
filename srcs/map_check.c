# include "../includes/so_long.h"

void map_check(char *map_str)
{
    empty_map(map_str);
    empty_lines(map_str);
    wrong_content(map_str);
    wrong_shape(map_str);
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
    size_t line_len;
    size_t i;
    size_t len;

    line_len = 0;
    i = 0;
    len = 0;
    printf("strlen = %zu\n", ft_strlen(map));
    while (map[i] )
    {
        printf("line len, len, i: %zu,  %zu, %zu\n", line_len, len, i);
        while(map[i] != '\n')
        {
            i++;
            line_len++;
        }
        printf("line len, len, i: %zu,  %zu, %zu\n", line_len, len, i);
        if (len == 0)
            len = line_len;
        else if (line_len != len)
        {
            printf("ERROR line len, len, i, map[i]: %zu,  %zu, %zu, %d\n", line_len, len, i, map[i]);
		    write_error("Wrong map shape!");
        }
        line_len = 0;
        if (map[i] == '\n')
            i++;
    }
}


// void wrong_shape(char *map)
// {
//     size_t line_len = 0;
//     size_t i = 0;
//     size_t len = 0;
//     int first_line = 1; // Flag to track the first line

//     while (map[i])
//     {
//         printf("line len, len, i: %zu,  %zu, %zu\n", line_len, len, i);
//         while (map[i % len] != '\n')
//         {
//             i++;
//             line_len++;
//         }
//         printf("line len, len, i: %zu,  %zu, %zu\n", line_len, len, i);
//         if (first_line)
//         {
//             len = line_len;
//             first_line = 0;
//         }
//         else if (line_len != len)
//         {
//             printf("ERROR line len, len, i: %zu,  %zu, %zu\n", line_len, len, i);
//             write_error("Wrong map shape!");
//         }
//         line_len = 0;
//         i++;
//     }
// }
