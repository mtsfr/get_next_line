/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-b <mfaria-b@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:46 by mfaria-b          #+#    #+#             */
/*   Updated: 2023/11/21 20:34:47 by mfaria-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(char *line, int fd)
{
	int		flag;
	char	*buffer;

	flag = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (flag > 0 && !ft_strchr(line, '\n'))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*cut_file(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (!*file)
		return (NULL);
	while (file[i] != '\n' && file[i])
	{
		i++;
	}
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i])
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*rest_file(char *file)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!(file[i]))
	{
		free(file);
		return (NULL);
	}
	if (file[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(file) + 1 - i));
	if (!rest)
		return (NULL);
	j = 0;
	while (file[i] != '\0')
		rest[j++] = file[i++];
	rest[j] = '\0';
	free(file);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = read_file(file, fd);
	if (!file)
		return (NULL);
	line = cut_line(file);
	file = rest_file(file);
	return (line);
}
