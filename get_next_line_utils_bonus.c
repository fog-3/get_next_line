/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:17:09 by fernando          #+#    #+#             */
/*   Updated: 2024/02/21 16:44:48 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] != c))
		i++;
	if (c == str[i])
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *frst, char *snd)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(frst) + ft_strlen(snd);
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res || (!frst && !snd))
		return (0);
	i = 0;
	if (frst)
	{
		while (frst[i])
		{
			res[i] = frst[i];
			i++;
		}
	}
	j = 0;
	if (snd)
	{
		while (snd[j])
			res[i++] = snd[j++];
	}
	res[i] = '\0';
	return (res);
}

void	ft_bzero(void *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(int n, int size)
{
	char	*res;

	res = (char *)malloc(n * size);
	if (!res)
		return (NULL);
	ft_bzero(res, n * size);
	return (res);
}
