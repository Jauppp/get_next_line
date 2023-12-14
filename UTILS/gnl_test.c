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

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	char	*linefd1;

	printf("BUFFER = %d\n", BUFFER_SIZE);
	fd1 = open("giantline_nl.txt", O_RDONLY);
	linefd1 = get_next_line(fd1);
	while (linefd1)
	{
		printf("%s", linefd1);
		free(linefd1);
		linefd1 = get_next_line(fd1);
	}
	if (linefd1)
		free(linefd1);
	close(fd1);
}
