/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:52:13 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/28 22:04:28 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_key_hook(int key, void *data)
{
	t_mapinfo	*info;

	info = (t_mapinfo *)data;
	if (key == 13)
		top(info);
	if (key == 1)
		buttom(info);
	if (key == 0)
		left(info);
	if (key == 2)
		right(info);
	if (key == 53)
		exit_game(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mapinfo	info[1];

	if (argc != 2)
	{
		write(2, "Error\nMAP name required !\n", 26);
		exit(1);
	}
	init(info);
	check_map_name(argv[1]);
	info->map_name = argv[1];
	read_map(info);
	info->width = ft_strlen(info->map[0]);
	playe_pos(info);
	check_for_valid_border(info);
	check_equale_size_line(info);
	check_for_valid_paths(info);
	count_elemts(info);
	render(info);
	mlx_key_hook(info->win_ptr, my_key_hook, info);
	mlx_hook(info->win_ptr, 17, 0, exit_game, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}

char	*ft_strjoinsolong(char *s1, char *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*ptr;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	free(s1);
	return (ptr);
}
