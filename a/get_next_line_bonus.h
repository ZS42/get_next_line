/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:38:12 by zsyyida           #+#    #+#             */
/*   Updated: 2022/07/07 12:30:37 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_line_len(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int n);
char	*ft_strndup(char *input, int n);
void	ft_free(char **p);
char	*ft_read(char *storage, int fd);
char	*ft_output(char **next_line);
char	*ft_nl_output(char	**next_line);
int		ft_strchr(char *next_line, int c);

#endif
