/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:52:13 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/26 23:52:06 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int my_key_hook(int key, void *data)
{
	t_mapinfo *info;
	
	info = (t_mapinfo*)data;
	if(key == 13) //W
		top(info);
	if(key == 1) //S
		buttom(info);
	if(key == 0) //A
		left(info);
	if(key == 2) //D
		right(info);
	if(key == 53) //exit
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		write(2, "MAP name required !\n", 20);
	}
	t_mapinfo *info = malloc(sizeof(t_mapinfo));
	if(!info)
		return (0);
	init(info);
	info->map_name = argv[1];
 	info->map = read_map(info);
	info->width = ft_strlen(info->map[0]);
	playe_pos(info);
	check_for_valid_border(info);
	check_equale_size_line(info);
	check_for_valid_paths(info);
	count_elemts(info);
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width  * 50, info->height * 50, "so_long");
	info->img = mlx_new_image(info->mlx_ptr, info->width  * 50 , info->height * 50);
	mlx_key_hook(info->win_ptr, my_key_hook, info );
	put_img(info);
	mlx_hook(info->win_ptr, 17, 0, exit_game, 0);
	mlx_loop(info->mlx_ptr);
	return 0;
}
