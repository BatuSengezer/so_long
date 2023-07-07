# include "../include/so_long.h"

t_img	*load_enemy_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/Enemy.png");
	if (!enemy)
		write_error("Error while loading png");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		write_error("Error during texture to image");
	mlx_delete_texture(enemy);
	return (img);
}

t_img	*load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./sprites/Player.png");
	if (!player)
		write_error("Error while loading png");
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
		write_error("Error during texture to image");
	mlx_delete_texture(player);
	return (img);
}

void	load_player_textures(t_game *game)
{
	game->player_up = mlx_load_png("./sprites/Player_Up.png");
	if (!game->player_up)
		write_error("Error while loading png");
	game->player_down = mlx_load_png("./sprites/Player_Down.png");
	if (!game->player_down)
		write_error("Error while loading png");
	game->player_left = mlx_load_png("./sprites/Player_Left.png");
	if (!game->player_left)
		write_error("Error while loading png");
	game->player_right = mlx_load_png("./sprites/Player_Right.png");
	if (!game->player_right)
		write_error("Error while loading png");
}

// void	load_player(t_game *game, char dir)
// {

// 	if (dir == 'u')
// 	{
// 		mlx_delete_image(game->mlx, game->img->player);
// 		game->img->player = mlx_texture_to_image(game->mlx, game->player_up);
// 		if (mlx_image_to_window(game->mlx, game->img->player, game->player_x * PIXELS, game->player_y * PIXELS) < 0)
// 			write_error("Error during img to window!"); 
// 	}
	// if (dir == 'd')
	// 	game->img->player = mlx_texture_to_image(game->mlx, game->player_down);
	// if (dir == 'r')
	// 	game->img->player = mlx_texture_to_image(game->mlx, game->player_right);
	// if (dir == 'l')
	// 	game->img->player = mlx_texture_to_image(game->mlx, game->player_left);

	// if (dir == 'u')
	// 	mlx_draw_texture(game->img->player, game->player_up, 0, 0);
	// if (dir == 'd')
	// 	mlx_draw_texture(game->img->player, game->player_down, 0, 0);
	// if (dir == 'r')
	// 	mlx_draw_texture(game->img->player, game->player_right, 0, 0);
	// if (dir == 'l')
	// 	mlx_draw_texture(game->img->player, game->player_left, 0, 0);
// }