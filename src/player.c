/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:49:31 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:33 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void	player_location(t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (row < mlx->row)
	{
		col = 0;
		while (col < mlx->col)
		{
			if (mlx->map[row][col] == 'P')
			{
				mlx->p_x = col * 32;
				mlx->p_y = row * 32;
			}
			col++;
		}
		row++;
	}
}

void	player_move(t_game *game, t_mlx	*mlx)
{
	mlx_key_hook(mlx->win, key_input, mlx);
}

int	key_input(int key, t_mlx *mlx)
{
	if (key == 'a')
		a_input(mlx);
	else if (key == 'd')
		d_input(mlx);
	else if (key == 'w')
		w_input(mlx);
	else if (key == 's')
		s_input(mlx);
	else if (key == 65307)
	{
		free_mlx(mlx);
		exit(0);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	map_print(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
							mlx->player, mlx->p_x, mlx->p_y);
	ft_printf("Steps: %i\n", mlx->p_steps);
	return (0);
}
