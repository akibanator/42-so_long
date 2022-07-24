/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:12:21 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:33 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_mlx	mlx;

	mlx.p_steps = 0;
	load_map(argc, argv, &game);
	map_size(&game);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, game.width, game.height, "so_long");
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	load_image(&game, &mlx);
	map_print(&mlx);
	initial_map(&game, &mlx);
	player_location(&mlx);
	player_move(&game, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	expose_hook(t_mlx *mlx)
{
	map_print(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
							mlx->player, mlx->p_x, mlx->p_y);
	return (0);
}

int	close_game(t_mlx *mlx)
{
	free_mlx(mlx);
	exit(0);
	return (1);
}

void	free_mlx(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
		free(mlx->map[i++]);
	free(mlx->map);
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx_destroy_image(mlx->mlx, mlx->tile);
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx_destroy_image(mlx->mlx, mlx->item);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
