/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:38:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:03 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	//int		fd2;
	//int		i;
	char	*linefd1;
	char	*linefd2;

	//i = 0;

	printf("BUFFER = %d\n", BUFFER_SIZE);
	fd1 = open("symphonie.txt", O_RDONLY);
	// fd2 = open("the_hobbit.txt", O_RDONLY);
	linefd1 = get_next_line(fd1);
	// linefd2 = get_next_line(fd2);
	while (linefd1)
	{
		printf("%s", linefd1);
		free(linefd1);
		linefd1 = get_next_line(fd1);
		//printf("%s", linefd2);
		//free(linefd2);
		//linefd2 = get_next_line(fd2);
	}
	close(fd1);
	//close(fd2);
}
