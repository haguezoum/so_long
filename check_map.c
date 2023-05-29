/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:48:36 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 00:02:49 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elemts(t_mapinfo *info)
{
	if (info->ccnt < 1)
	{
		free_double_pointer(info->map);
		error("Error\nThe map must contain 1 Collectible at least !");
	}
	else if (info->player_count < 1 || info->player_count > 1)
	{
		free_double_pointer(info->map);
		error("Error\nThe map must contain 1 Player!");
	}
	else if (info->exit_count < 1 || info->exit_count > 1)
	{
		free_double_pointer(info->map);
		error("Error\nThe map must contain 1 Exit!");
	}
	return (0);
}

void	count_elemts(t_mapinfo *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j <= info->width)
		{
			if (info->map[i][j] == 'C')
			info->ccnt += 1;
			if (info->map[i][j] == '0')
				info->space_count += 1;
			if (info->map[i][j] == 'E')
				info->exit_count += 1;
			if (info->map[i][j] == 'P')
				info->player_count += 1;
		}
	}
	check_elemts(info);
}

void	check_equale_size_line(t_mapinfo *info)
{
	int	i;

	i = -1;
	if (info->width > 51 || info->height > 28)
	{
		free_double_pointer(info->map);
		error("Error\nOut of window limits !");
	}
	while (++i < info->height)
	{
		if ((int)ft_strlen(info->map[i]) - 1 != info->width - 1)
		{
			free_double_pointer(info->map);
			error("Error\nNot equale border size !");
		}
	}
}

void	check_for_valid_border(t_mapinfo *info)
{
	int	i;

	i = -1;
	while (++i <= (info->width - 1))
	{
		if ((info->map[0][i] != '1'
			||info->map[info->height - 1][i] != '1'))
		{
			free_double_pointer(info->map);
			error("Invalid map ! \n(side Borders not 1 or empty line)");
		}
	}
	i = -1;
	while (++i <= (info->height - 1))
	{
		if (info->map[i][0] != '1'
			|| info->map[i][info->width - 1] != '1' || info->map[i][0] == '\n')
		{
			free_double_pointer(info->map);
			error("Invalid map ! \n(side Borders not 1)");
		}
	}
}

void	read_map(t_mapinfo *info)
{
	int		fd;
	char	*line;
	char	*tofree;

	fd = open(info->map_name, O_RDONLY);
	tofree = get_next_line(fd);
	if (!tofree || fd == -1)
		error("Error \nInvalid FD! or Empty Map");
	line = ft_strdup("");
	while (tofree)
	{
		if (!tofree)
			break ;
		line = ft_strjoinsolong(line, tofree);
		free(tofree);
		info->height += 1;
		tofree = get_next_line(fd);
	}
	info->map = ft_split(line, '\n');
	free(tofree);
	free(line);
	close(fd);
	fd = open(info->map_name, O_RDONLY);
	check_empty_line_in_map(fd, info->height);
}
