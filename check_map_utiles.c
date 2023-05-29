/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:26:36 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 01:06:46 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_empty_line_in_map(int fd, int height)
{
	int		i;
	char	*next_line;

	i = 0;
	while (i < height)
	{
		next_line = get_next_line(fd);
		if (next_line[0] == '\n' || next_line[0] == '\0')
		{
			free(next_line);
			error("Error\nInvalid MAP !\n");
		}
		free(next_line);
		i++;
	}
	close(fd);
}
