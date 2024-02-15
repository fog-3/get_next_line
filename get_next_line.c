/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:45:07 by fernando          #+#    #+#             */
/*   Updated: 2024/02/15 12:50:20 by fernando         ###   ########.fr       */
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

char	*ft_rest_next_line(char *lect)
{
	
}

char	*ft_read_line(char *lect, char *line)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	while (lect[i])
	{
		if (lect[i] == '\n' || j > 0)
			j++;
		i++;
	}
	aux = (char *)malloc(sizeof(char) * (j + 1));
	if (!aux)
		return (0);
	i -= j;
	j = 0;
	while (lect[i])
	{
		aux[j] = lect[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	i -= j;
	j = 0;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	while (j < i)
	{
		line[j] = lect[j];
		lect[j] = '\0';
		j++;
	}
	if (lect[i] == '\n')
		line[j++] = '\n';
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
