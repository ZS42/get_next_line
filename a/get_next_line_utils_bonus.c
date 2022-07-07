/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:55:13 by zsyyida           #+#    #+#             */
/*   Updated: 2022/07/07 15:04:13 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

//checks for next \n or \0
int	ft_strchr(char *storage, int c)
{
	int	i;

	i = 0;
	while (storage[i] != '\0' && *storage)
	{
		if (storage[i] == (char) c)
			return (1);
		i++;
	}
	if (storage[i] == '\0')
		return (0);
	else
		return (2);
}

//finds length till and including next \n or upto \0
int	ft_line_len(char *storage, int c)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i] && *storage)
	{
		if (storage[i] == (char) c)
		{
			i += 1;
			return (i);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

//joins leftover in static to new read in buffer
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char		*output;
	int			l1;
	int			i;
	int			j;

	i = 0;
	j = -1;
	l1 = ft_strlen(s1);
	output = malloc(l1 + n + 1);
	if (!output)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[++j])
		output[i + j] = s2[j];
	output[i + j] = '\0';
	if (s1)
		ft_free(&s1);
	return (output);
}

// frees pointer and sets it to NULL
void	ft_free(char **p)
{
	free(*p);
	*p = NULL;
}
