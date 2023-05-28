/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:29:33 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/28 14:01:42 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_double_pointer(char **ptr)
{
    int	i;

	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
	}
	free(ptr);
}
int check_elemnt_count(char **map, int width, int height , t_mapinfo *info)
{
    int i;
    int j;
    int k;
    i = -1;
    k = -1;
    while (++i < height)
    {   
        j = -1;
        while (++j <= width)
            if(map[i][j] == 'C' || map[i][j] == 'E')
            {
                while(++k < info->height)
                    free(map[k]);
                free(map);
                k = -1;
                while(++k < info->height)
                    free(info->map[k]);
                free(info->map);
                // free_double_pointer(info->map);
                free(info);
                while (1)
                {
                    /* code */
                }
                error("Error \n Invalid MAP C E!\n");
                return 0;
            }
    }
    return 1;
}
void valid_path_util(char** map, int i, int j, int *bool)
{
    map[i][j] = 'P';
    *bool = 1;
}
void valid_path(char **s_map, int width, int height, int *replaced)
{
    int i;
    int j;
    i = -1;
    while(++i < height)
    {
        j = 0;
        while (j <= width)
        {
            if(s_map[i][j] == 'P')
            {
                if (i > 0 && (s_map[i - 1][j] == 'C' || s_map[i - 1][j] == '0' || s_map[i - 1][j] == 'E') )
                    valid_path_util(s_map, i - 1, j, replaced);
                if (i < height - 1 && (s_map[i + 1][j] == 'C' || s_map[i + 1][j] == '0' || s_map[i + 1][j] == 'E') )
                    valid_path_util(s_map, i + 1, j, replaced);
                if (j > 0 && (s_map[i][j - 1] == 'C' || s_map[i][j - 1] == '0' || s_map[i][j - 1] == 'E') ) 
                    valid_path_util(s_map, i, j - 1, replaced);
                if (j < width && (s_map[i][j + 1] == 'C' || s_map[i][j + 1] == '0' || s_map[i][j + 1] == 'E') )
                   valid_path_util(s_map, i , j + 1, replaced);
            }
            j++;
        }
    }
    // return (s_map);
}
void check_for_valid_paths(t_mapinfo *info)
{ 
    int i;
    char **map;
    int replaced;
    map = info->map;
    i = -1;
    map = malloc(sizeof(char*) * info->height);
    if(!map)
        return ;
    while(++i < info->height)
        map[i] = ft_strdup(info->map[i]);
    replaced = 1;
    while(replaced)
    { 
        replaced = 0;
        valid_path(map, info->width, info->height, &replaced);
    }
    if(check_elemnt_count(map, info->width, info->height, info))
    {
        i = -1;
        while(++i < info->height)
            free(map[i]);
        free(map);
    }
}