/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-b <mfaria-b@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:25:46 by mfaria-b          #+#    #+#             */
/*   Updated: 2023/11/17 15:37:10 by mfaria-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*rest_file(char *file)
{

}

static char	*cut_file(char *file)
{

}

static char	*read_file(char *line, int fd)
{

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
	file = rest+file(file);
	return (line);
}
