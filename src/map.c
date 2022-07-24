/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:49:27 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:32 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void	map_size(t_game *game)
{
	game->width = game->col * 32;
	game->height = game->row * 32;
}

void	map_print(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < mlx->row)
	{
		col = 0;
		while (col < mlx->col)
		{
			if (mlx->map[row][col] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, \
										(col * 32), (row * 32));
			else if (mlx->map[row][col] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, \
										(col * 32), (row * 32));
			else if (mlx->map[row][col] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item, \
										(col * 32), (row * 32));
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tile, \
										(col * 32), (row * 32));
			col++;
		}
		row++;
	}
}

void	load_image(t_game *game, t_mlx *mlx)
{
	mlx->mlx_c_count = 0;
	mlx->game_c_count = game->c_count;
	mlx->map = game->map;
	mlx->col = game->col;
	mlx->row = game->row;
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, \
									"images/wall.xpm", &mlx->x, &mlx->y);
	mlx->tile = mlx_xpm_file_to_image(mlx->mlx, \
									"images/tile.xpm", &mlx->x, &mlx->y);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, \
									"images/player.xpm", &mlx->x, &mlx->y);
	mlx->item = mlx_xpm_file_to_image(mlx->mlx, \
									"images/item.xpm", &mlx->x, &mlx->y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, \
									"images/exit.xpm", &mlx->x, &mlx->y);
}

void	initial_map(t_game *game, t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (game->map[row][col] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, \
										(col * 32), (row * 32));
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item, \
										(col * 32), (row * 32));
			if (game->map[row][col] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, \
										(col * 32), (row * 32));
		col++;
		}
	row++;
	}
}
