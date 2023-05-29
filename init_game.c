/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:52:58 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 00:40:41 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_elemnt(t_mapinfo *info);

void	init(t_mapinfo *info)
{
	info->width = 0;
	info->height = 0;
	info->space_count = 0;
	info->player_count = 0;
	info->ccnt = 0;
	info->exit_count = 0;
	info->p_pos_x = 0;
	info->p_pos_y = 0;
	info->mlx_ptr = mlx_init();
	info->space_path = "./xpm_img/space.xpm";
	info->wall_path = "./xpm_img/brick.xpm";
	info->player_path = "./xpm_img/sus.xpm";
	info->collectible_path = "./xpm_img/collect.xpm";
	info->exit_path = "./xpm_img/door.xpm";
	info->move_count = 0;
	init_elemnt(info);
}

void	init_elemnt(t_mapinfo *info)
{
	int	width;
	int	height;

	info->wall = mlx_xpm_file_to_image(info->mlx_ptr,
			info->wall_path, &width, &height);
	info->player = mlx_xpm_file_to_image(info->mlx_ptr,
			info->player_path, &width, &height);
	info->collectible = mlx_xpm_file_to_image(info->mlx_ptr,
			info->collectible_path, &width, &height);
	info->space = mlx_xpm_file_to_image(info->mlx_ptr,
			info->space_path, &width, &height);
	info->exit = mlx_xpm_file_to_image(info->mlx_ptr,
			info->exit_path, &width, &height);
	if (info->wall == NULL || info->player == NULL
		|| info->collectible == NULL || info->space == NULL)
	{
		error("Error\nInvalid image !");
		exit(1);
	}
}

void	render(t_mapinfo *info)
{
		info->win_ptr = mlx_new_window(info->mlx_ptr, info->width * 50,
			info->height * 50, "so_long");
	info->img = mlx_new_image(info->mlx_ptr, info->width * 50,
			info->height * 50);
	put_img(info);
}

void	check_map_name(char *name)
{
	int		len;
	char	*str;

	len = ft_strlen(name) - 4;
	str = ft_substr(name, len, 4);
	if (ft_strncmp(str, ".ber", 4))
	{
		free(str);
		error("Error\nMap extention must be .ber !");
	}
	free(str);
}

void	playe_pos(t_mapinfo *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j <= info->width)
		{
			if (info->map[i][j] == 'P')
			{
				info->p_pos_x = j;
				info->p_pos_y = i;
				break ;
			}
		}
	}
}
