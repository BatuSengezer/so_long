# include "../includes/so_long.h"

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
