/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:33:23 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/25 00:40:31 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void	load_map(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("\nError\nThere's something wrong with the argument\n");
		exit (1);
	}
	else
	{
		game->map_file = argv[1];
		if (!check_typefile(game, "ber"))
		{
			ft_printf("\nError\nThere is something ");
			ft_printf("wrong with the file extension\n");
			exit(1);
		}
		ft_printf("Map file: %s\n", game->map_file);
	}
	read_map_file(game);
}

void	read_map_file(t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	map_count_rows(game);
	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
		error_file();
	i = 0;
	while (fd)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		game->map[i] = ft_strdup(temp);
		i++;
		free(temp);
	}
	game->map[game->row] = NULL;
	game->col = ft_strlen(game->map[0]);
	game->col--;
	close(fd);
	map_check_wall(game);
	map_check_inside(game);
}

void	map_count_rows(t_game *game)
{
	int		fd;
	int		res;
	char	c;

	fd = open(game->map_file, O_RDONLY);
	if (!fd)
		error_file();
	game->row = 1;
	res = 1;
	while (res)
	{
		res = read(fd, &c, 1);
		if (res <= 0)
			res = 0;
		if (c == '\n')
			game->row++;
	}
	game->map = (char **) ft_calloc(game->row + 1, sizeof(char *));
	if (game->map == NULL)
	{
		free_game(game);
		error_file();
	}
	close (fd);
}

void	map_check_wall(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (row == 0 || row == (game->row - 1) || \
			col == 0 || col == (game->col - 1))
			{
				if (game->map[row][col] != '1')
				{
					ft_printf("\nError\nThere's something wrong with the walls\n");
					free_game(game);
					exit(1);
				}
			}
			col++;
		}
		row++;
	}
}

void	map_check_inside(t_game *game)
{
	int	row;
	int	col;

	game->c_count = 0;
	game->p_count = 0;
	game->e_count = 0;
	row = 0;
	while (row < game->row)
	{
		col = 0;
		while (col < game->col)
		{
			if (game->map[row][col] == 'C')
				game->c_count++;
			if (game->map[row][col] == 'P')
				game->p_count++;
			if (game->map[row][col] == 'E')
				game->e_count++;
			col++;
		}
		row++;
	}
	check_inside_error(game);
	map_check_floor(game);
}
