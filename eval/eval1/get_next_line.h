/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:25:55 by zsyyida           #+#    #+#             */
/*   Updated: 2022/06/30 16:16:39 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_line_len(char *s, int c);
char	*ft_strdup_update(char *s1);
int		ft_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_strndup(char *input, int n);
void	ft_free(char **p);
void	*ft_memcpy(char *dst, char *src, int n);
char	*ft_output(char **next_line);
char	*ft_nl_output(char	**next_line);
int		ft_strchr(char *next_line, int c);

#endif
