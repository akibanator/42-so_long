/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akenji-a <akenji-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:49:27 by akenji-a          #+#    #+#             */
/*   Updated: 2022/07/24 20:56:30 by akenji-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct s_game
{
	char	**map;
	char	*map_file;
	int		row;
	int		col;
	int		p_count;
	int		c_count;
	int		e_count;
	int		width;
	int		height;
}	t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*exit;
	void	*player;
	void	*item;
	void	*tile;
	char	**map;
	int		row;
	int		col;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		mlx_c_count;
	int		game_c_count;
	int		p_steps;
}	t_mlx;

int		expose_hook(t_mlx *mlx);
int		close_game(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
void	player_location(t_mlx *mlx);
void	player_move(t_game *game, t_mlx	*mlx);
int		key_input(int key, t_mlx *mlx);
void	map_size(t_game *game);
void	map_print(t_mlx *mlx);
void	load_image(t_game *game, t_mlx *mlx);
void	initial_map(t_game *game, t_mlx *mlx);
void	load_map(int argc, char **argv, t_game *game);
void	read_map_file(t_game *game);
void	map_count_rows(t_game *game);
void	map_check_wall(t_game *game);
void	map_check_inside(t_game *game);
void	a_input(t_mlx *mlx);
void	d_input(t_mlx *mlx);
void	w_input(t_mlx *mlx);
void	s_input(t_mlx *mlx);
void	a_input_exit(t_mlx *mlx);
void	d_input_exit(t_mlx *mlx);
void	w_input_exit(t_mlx *mlx);
void	s_input_exit(t_mlx *mlx);
int		check_typefile(t_game *game, char *type);
void	error_file(void);
void	check_inside_error(t_game *game);
void	map_check_floor(t_game *game);
void	free_game(t_game *game);

#endif
