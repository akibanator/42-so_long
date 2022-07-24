/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:49:12 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:29 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void	a_input_exit(t_mlx *mlx)
{
	if (mlx->mlx_c_count == mlx->game_c_count)
	{
		free_mlx(mlx);
		ft_printf("\nCongratulations!!\n");
		exit(0);
	}
	else
	{
		mlx->p_x += 32;
		mlx->p_steps--;
	}
}

void	d_input_exit(t_mlx *mlx)
{
	if (mlx->mlx_c_count == mlx->game_c_count)
	{
		free_mlx(mlx);
		ft_printf("\nCongratulations!!\n");
		exit(0);
	}
	else
	{
		mlx->p_x -= 32;
		mlx->p_steps--;
	}
}

void	w_input_exit(t_mlx *mlx)
{
	if (mlx->mlx_c_count == mlx->game_c_count)
	{
		free_mlx(mlx);
		ft_printf("\nCongratulations!!\n");
		exit(0);
	}
	else
	{
		mlx->p_y += 32;
		mlx->p_steps--;
	}
}

void	s_input_exit(t_mlx *mlx)
{
	if (mlx->mlx_c_count == mlx->game_c_count)
	{
		free_mlx(mlx);
		ft_printf("\nCongratulations!!\n");
		exit(0);
	}
	else
	{
		mlx->p_y -= 32;
		mlx->p_steps--;
	}
}
