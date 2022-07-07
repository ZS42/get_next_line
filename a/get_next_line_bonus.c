/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:50:36 by zsyyida           #+#    #+#             */
/*   Updated: 2022/07/07 15:09:14 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
// #include <fcntl.h>

// ft_str_dup with len duplicates upto and including /n
char	*ft_strdup(char *s1, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (0);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

// gives output based on if \0 (i = 0) or \n (i = 1)
//if \0 will duplicate into line so can free static variable
char	*ft_output(char **storage)
{
	char	*line;
	int		i;
	int		len;

	line = NULL;
	i = 0;
	if (!*storage || ft_strlen(*storage) == 0)
	{
		ft_free(storage);
		return (NULL);
	}
	i = ft_strchr(*storage, '\n');
	if (i == 0)
	{
		len = ft_strlen(*storage);
		line = ft_strdup(*storage, len);
		ft_free(storage);
	}
	else if (i == 1)
	{
		line = ft_nl_output (storage);
	}
	else if (i == 2)
		return (NULL);
	return (line);
}

//when sending ** to ** send without & or * when sending it to * send with *
// will duplicate into line upto \n
// will free static if at end
//if not at end will update static to leftover after \n using temp updated_line
char	*ft_nl_output(char	**storage)
{
	char	*line;
	int		len;
	char	*updated_line;
	int		i;

	i = 0;
	i = ft_strlen(*storage);
	updated_line = NULL;
	len = ft_line_len(*storage, '\n');
	line = ft_strdup(*storage, len);
	if (i == (len))
		ft_free(storage);
	else
	{
		updated_line = ft_strdup(*storage + len, (i - len));
		ft_free (storage);
		*storage = updated_line;
	}
	return (line);
}

//bytes is the number of bytes read.
//put in a condition to not reenter loop if '\n' or '\0'
//do not put condition ft_strchr = 0 bc we are always putting \0 in
//strjoin so it will always break. Instead put if bytes < BUFFER_SIZE
//check for negative reads to prevent invalid read/write
char	*ft_read(char *storage, int fd)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		buff = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			ft_free(&buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		storage = ft_strnjoin(storage, buff, bytes);
		ft_free(&buff);
		if (bytes < BUFFER_SIZE || (ft_strchr(storage, '\n') == 1))
			break ;
	}
	ft_free(&buff);
	return (storage);
}

//when initialising send as & in that function
//when sending to ** send as & otherwise sending to * send withour & or *
//next_line is the read line upto and including \n or \0 that will be returned
char	*get_next_line(int fd)
{
	static char	*storage[999];
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 999)
		return (NULL);
	storage[fd] = ft_read(storage[fd], fd);
	next_line = ft_output (&storage[fd]);
	if (ft_strlen(next_line) == 0)
	{
		ft_free (&storage[fd]);
		return (NULL);
	}
	return (next_line);
}
