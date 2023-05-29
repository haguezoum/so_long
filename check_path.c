/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:29:33 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 00:39:38 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
	}
	free(ptr);
}

int	check_elemnt_count(char **map, int width, int height)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < height)
	{
		j = 0;
		while (++j <= width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				return (-1);
			}
		}
	}
	return (1);
}

void	set_player(char **map, int i, int j, int *bool)
{
	map[i][j] = 'P';
	*bool = 1;
}

void	valid_path(char **s_map, t_mapinfo *info, int *replaced, int i)
{
	int	j;

	while (++i < info->height)
	{
		j = -1;
		while (++j <= info->width)
		{
			if (s_map[i][j] == 'P')
			{
				if (i > 0 && (s_map[i - 1][j] == 'C'
					||s_map[i - 1][j] == '0' || s_map[i - 1][j] == 'E'))
					set_player(s_map, i - 1, j, replaced);
				else if (i < info->height - 1 && (s_map[i + 1][j] == 'C'
					|| s_map[i + 1][j] == '0' || s_map[i + 1][j] == 'E'))
					set_player(s_map, i + 1, j, replaced);
				else if (j > 0 && (s_map[i][j - 1] == 'C'
					|| s_map[i][j - 1] == '0' || s_map[i][j - 1] == 'E'))
					set_player(s_map, i, j - 1, replaced);
				else if (j < info->width && (s_map[i][j + 1] == 'C'
					|| s_map[i][j + 1] == '0' || s_map[i][j + 1] == 'E'))
					set_player(s_map, i, j + 1, replaced);
			}
		}
	}
}

void	check_for_valid_paths(t_mapinfo *info)
{
	int		i;
	int		replaced;
	char	**map;

	i = -1;
	map = (char **)malloc(sizeof(char *) * info->height);
	if (!map)
		return ;
	while (info->map[++i])
		map[i] = ft_strdup(info->map[i]);
	replaced = 1;
	while (replaced)
	{
		replaced = 0;
		valid_path(map, info, &replaced, -1);
	}
	if (check_elemnt_count(map, info->width, info->height) < 0)
		error("Error\nInvalid MAP\n");
	else
	{
		i = -1;
		while (++i < info->height)
			free(map[i]);
		free(map);
	}
}
