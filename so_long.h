/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:49:48 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 00:44:10 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		screen_width;
	int		screen_height;
	int		width;
	int		height;
	int		space_count;
	int		player_count;
	int		ccnt;
	int		exit_count;
	int		p_pos_x;
	int		p_pos_y;
	void	*img;
	void	*wall;
	void	*space;
	void	*player;
	void	*exit;
	void	*collectible;
	char	*space_path;
	char	*wall_path ;
	char	*player_path;
	char	*collectible_path;
	char	*exit_path;
	int		move_count;
	char	*map_name;
}	t_mapinfo;

void	error(char *msg);
void	init(t_mapinfo *info);
void	read_map(t_mapinfo *info);
void	check_for_valid_paths(t_mapinfo *info);
void	check_for_valid_border(t_mapinfo *info);
void	check_equale_size_line(t_mapinfo *info);
void	count_elemts(t_mapinfo *info);
int		check_elemts(t_mapinfo *info);
void	put_img(t_mapinfo *info);
void	left(t_mapinfo *info);
void	right(t_mapinfo *info);
void	top(t_mapinfo *info);
void	buttom(t_mapinfo *info);
void	playe_pos(t_mapinfo *info);
void	move_counter(t_mapinfo *info);
int		exit_game(t_mapinfo *info);
void	free_double_pointer(char **ptr);
char	*ft_strjoinsolong(char *s1, char *s2);
void	check_empty_line_in_map(int fd, int height);
void	set_player(char **map, int i, int j, int *bool);
void	render(t_mapinfo *info);
void	check_map_name(char *name);
#endif