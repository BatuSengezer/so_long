# include "../include/so_long.h"

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
//     check_file_extension(av[1]);
//     game = game_init(av[1]);
    

//     return (0);
// }

// test main
int main(int ac, char **av)
{   
    t_game  *game;
    t_img   *images;
    // remove that later
    if (av == 0)
        return (0);
    //

    if (ac!= 2)
        write_error("Argument count should be 2!");
    check_file_extension(av[1]);
    game = init_game(av[1]);
    game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
    if (!game->mlx)
		return (EXIT_FAILURE);
	images = init_img_struct(game->mlx);
    game->img = images;
	fill_background(game);


    printf("player_x: %zu\n", game->player_x);
    printf("player_y: %zu\n", game->player_y);
	printf("exit_x: %zu\n", game->exit_x);
    printf("exit_y: %zu\n", game->exit_y);
    return (0);
}