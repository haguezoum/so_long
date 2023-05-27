/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:54 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/12 22:45:48 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include "../libft/libft.h"

char	*chunck(char *s)
{
	int	i;

	i = 0;
	if (s[0] == 0)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*restof(char *s)
{
	int		i;
	int		s_len;
	char	*line;

	s_len = (int)ft_strlen(s);
	i = 0;
	if (s[i] == 0)
	{
		free(s);
		return (NULL);
	}
	while (s[i] != '\n' && s[i])
		i++;
	line = ft_substr((char *)s, i + 1, s_len - (i));
	free(s);
	return (line);
}

char	*string(int fd, char *line)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (free(line), NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(line);
			line = NULL;
			return (line);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = string(fd, line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	tmp = chunck(line);
	line = restof(line);
	return (tmp);
}
