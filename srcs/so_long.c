# include "../includes/so_long.h"

int main(int ac, char **av)
{   
    // t_game  *game;
    //t_img   *images;
    // remove that later
    if (av == 0)
        return (0);
    //
    if (ac!= 2)
        write_error("Argument count should be 2!");
    // game = game_init(av[1]);
    game_init(av[1]);
    
    return (0);
}