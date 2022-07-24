/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:11:17 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:30 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void	a_input(t_mlx *mlx)
{
	mlx->p_x -= 32;
	mlx->p_steps++;
	if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == '1')
	{
		mlx->p_x += 32;
		mlx->p_steps--;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'C')
	{
		mlx->map[mlx->p_y / 32][mlx->p_x / 32] = '0';
		mlx->mlx_c_count++;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'E')
	{
		a_input_exit(mlx);
	}
}

void	d_input(t_mlx *mlx)
{
	mlx->p_x += 32;
	mlx->p_steps++;
	if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == '1')
	{
		mlx->p_x -= 32;
		mlx->p_steps--;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'C')
	{
		mlx->map[mlx->p_y / 32][mlx->p_x / 32] = '0';
		mlx->mlx_c_count++;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'E')
	{
		d_input_exit(mlx);
	}
}

void	w_input(t_mlx *mlx)
{
	mlx->p_y -= 32;
	mlx->p_steps++;
	if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == '1')
	{
		mlx->p_y += 32;
		mlx->p_steps--;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'C')
	{
		mlx->map[mlx->p_y / 32][mlx->p_x / 32] = '0';
		mlx->mlx_c_count++;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'E')
	{
		w_input_exit(mlx);
	}
}

void	s_input(t_mlx *mlx)
{
	mlx->p_y += 32;
	mlx->p_steps++;
	if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == '1')
	{
		mlx->p_y -= 32;
		mlx->p_steps--;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'C')
	{
		mlx->map[mlx->p_y / 32][mlx->p_x / 32] = '0';
		mlx->mlx_c_count++;
	}
	else if (mlx->map[mlx->p_y / 32][mlx->p_x / 32] == 'E')
	{
		s_input_exit(mlx);
	}
}
