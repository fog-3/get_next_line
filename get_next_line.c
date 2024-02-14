/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:45:07 by fernando          #+#    #+#             */
/*   Updated: 2024/02/14 19:48:59 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_arc(int fd, char *buffer, char *lect)
{
	int	buffn;

	buffn = read(fd, buffer, BUFFER_SIZE);
	while (buffn < 0 || !ft_strchr(lect, '\n'))
	{
		lect = ft_strjoin(lect, buffer);
		buffn = read(fd, buffer, BUFFER_SIZE);
		if (buffn < 0)
			free(buffer);
	}
	return (free(buffer), lect);
}

char	*ft_read_line(char *lect, char *line)
{
	int		i;
	char	*aux;

	i = 0;
	j = 0;
	while (lect[i])
	{
		if (lect[i] == '\n' || j > 0)
			j++;
		i++;
	}
	aux = (char *)malloc(sizeof(char) * j);
	i -= j;
	j = 0;
	while (lect[i])
	{
		aux[j] = lect[i];
		i++;
	}
	if (!aux)
		return (0);
	free(aux);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*lect;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	lect = ft_read_arc(fd, buffer, lect);
	line = ft_read_line(lect, line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
