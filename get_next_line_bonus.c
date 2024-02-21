/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:16:50 by fernando          #+#    #+#             */
/*   Updated: 2024/02/21 16:58:45 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_free(char *lect, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(lect, buffer);
	free(lect);
	lect = NULL;
	return (temp);
}

char	*ft_read_arc(int fd, char *lect)
{
	int		buffn;
	char	*buffer;

	if (!lect)
		lect = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffn = 1;
	while (buffn > 0 && !ft_strchr(lect, '\n'))
	{
		buffn = read(fd, buffer, BUFFER_SIZE);
		if (buffn < 0)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[buffn] = '\0';
		lect = ft_free(lect, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (lect);
}

char	*ft_next(char *lect)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lect[i] && lect[i] != '\n')
		i++;
	if (!lect[i])
	{
		free(lect);
		lect = NULL;
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(lect) - i + 1), sizeof(char));
	if (!aux)
		return (0);
	i++;
	j = 0;
	while (lect[i])
		aux[j++] = lect[i++];
	free(lect);
	lect = NULL;
	return (aux);
}

char	*ft_read_line(char *lect)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!lect[i])
		return (0);
	while (lect[i] && lect[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	j = 0;
	while (lect[j] && lect[j] != '\n')
	{
		line[j] = lect[j];
		j++;
	}
	if (lect[j] == '\n' && lect[j])
		line[j++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lect[1000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		free(lect[fd]);
		lect[fd] = NULL;
		return (NULL);
	}
	lect[fd] = ft_read_arc(fd, lect[fd]);
	if (!lect[fd])
		return (0);
	line = ft_read_line(lect[fd]);
	lect[fd] = ft_next(lect[fd]);
	return (line);
}
