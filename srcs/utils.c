# include "../include/so_long.h"

void write_error(char *str)
{
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(str, 2);
    exit (1);
        // add free map here if there is memory leak
}