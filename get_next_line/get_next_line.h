/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:50 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/12 22:38:39 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
 # include "../libft/libft.h"

char	*get_next_line(int fd);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// int		ft_strchr(const char *s, char c);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlen(char *s);
// char	*ft_calloc(int count, int size);
#endif
