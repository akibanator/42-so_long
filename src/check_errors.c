/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:56:32 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:27 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

int	check_typefile(t_game *game, char *type)
{
	int	i;
	int	len;

	len = ft_strlen(type);
	i = 0;
	while (game->map_file[i + 1])
		i++;
	while (i >= 0 && game->map_file[i] != '.')
		i--;
	if (i >= 0 && !ft_strncmp(game->map_file + i + 1, type, len))
		return (1);
	return (0);
}

void	error_file(void)
{
	ft_printf("\nErro\nThere is an error in the map file\n");
	exit(1);
}

void	check_inside_error(t_game *game)
{
	if (game->e_count == 0)
	{
		ft_printf("\nError\nMap file: there is something wrong with the exit\n");
		free_game(game);
		exit(1);
	}
	if (game->p_count == 0)
	{
		ft_printf("\nError\nMap file: there is something wrong with the player\n");
		free_game(game);
		exit(1);
	}
	if (game->c_count == 0)
	{
		ft_printf("\nError\nMap file: there is something wrong with the item\n");
		free_game(game);
		exit(1);
	}
}

void	map_check_floor(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (!(game->map[row][col] == '0' || game->map[row][col] == '1' || \
			game->map[row][col] == 'P' || game->map[row][col] == 'C' || \
			game->map[row][col] == 'E'))
			{
				ft_printf("\nError\nMap file: there is something ");
				ft_printf("wrong with the floor\n");
				free_game(game);
				exit(1);
			}
			col++;
		}
		row++;
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}
