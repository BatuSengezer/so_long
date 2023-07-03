# include "../includes/so_long.h"

// int main(int ac, char **av)
// {   
//      t_game  *game;
//     //t_img   *images;
//     // remove that later
//     if (av == 0)
//         return (0);
//     //
//     if (ac!= 2)
//         write_error("Argument count should be 2!");
//     game = game_init(av[1]);    
//     return (0);
// }



// test main
int main(int ac, char **av)
{   
    t_game  *game;
    //t_img   *images;
    // remove that later
    if (av == 0)
        return (0);
    //
    if (ac!= 2)
        write_error("Argument count should be 2!");
    game = game_init(av[1]);
    printf("player_x: %zu\n", game->player_x);
    printf("player_y: %zu\n", game->player_y);
	printf("exit_x: %zu\n", game->exit_x);
    printf("exit_y: %zu\n", game->exit_y);
    return (0);
}