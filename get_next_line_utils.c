/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:10:28 by fernando          #+#    #+#             */
/*   Updated: 2024/02/15 12:14:27 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(const char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && (str[i] != c))
        i++;
    if (c == str[i])
        return (1);
    return (0);
}
