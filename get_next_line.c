/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:45:07 by fernando          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
		ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffn = 1;
	while (buffn > 0 && !ft_strchr(lect, '\n'))
	{
		buffn = read(fd, buffer, BUFFER_SIZE);
		if (buffn < 0)
			return (free(buffer), NULL);
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
	aux = (char *)malloc((ft_strlen(lect) - i + 1) * sizeof(char));
	if (!aux)
		return (0);
	i++;
	j = 0;
	while (lect[i])
		aux[j++] = lect[i++];
	aux[j] = '\0';
	free(lect);
	lect = NULL;
	return (aux);
}

char	*ft_read_line(char *lect, char *line)
{
	int		i;
	int		j;

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
	if (lect[j] == '\n' || lect[j])
		line[j++] = '\n';
	line[j] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lect;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		free(lect);
		lect = NULL;
		return (NULL);
	}
	lect = ft_read_arc(fd, lect);
	if (!lect)
		return (0);
	line = ft_read_line(lect, line);
	lect = ft_next(lect);
	return (line);
}

/* int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
} */
