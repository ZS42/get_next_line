/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:07:29 by zsyyida           #+#    #+#             */
/*   Updated: 2022/07/07 13:53:30 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

// #include "./get_next_line_utils_bonus.c"
// #include "./get_next_line_bonus.c"

int	main(void)
{
	// char *line = get_next_line(0);

	// printf("%s", line);
	// free(line);

	int		fd;
	// int		fd1;
	// int		fd2;
	char	*ptr;

	fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
	 //fd = open("text", O_RDONLY);
	// printf("%d\n", BUFFER_SIZE);
	// ptr = NULL;
	// // ptr = "a";
	// for (int i = 0 ; i < 10; ++i)
	// {
	// 	ptr = get_next_line(fd);
	// 	printf("%s", ptr);
	// 	if (ptr)
	// 		free(ptr);
	// }
	// return 0;
// }

	ptr = get_next_line(fd);
	printf("line1:[%s]", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("line2:[%s]", ptr);
	free(ptr);

 	ptr = get_next_line(fd);
 	printf("line3:[%s]", ptr);
	free(ptr);

 	ptr = get_next_line(fd);
 	printf("line4%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
 	printf("line5%s", ptr);
	free(ptr);

	ptr = get_next_line(fd);
	printf("line6%s", ptr);
	free(ptr);
}

// int	main()
// {
// 	char	*ptr;
// 	int	fd;

// 	ptr = NULL;
// 	fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
// 	ptr = get_next_line(fd);
// 	printf("%s", ptr);
// 	free(ptr);
// 	while (*ptr != '\0')
// 	{
// 		ptr = get_next_line(fd);
// 		printf("%s", ptr);
// 		if (ptr)
// 			free(ptr);
// 	}
// 	ptr ++;
// }

