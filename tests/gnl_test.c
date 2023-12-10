/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:38:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/08 16:51:55 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	printf("BUFFER = %d\n", BUFFER_SIZE);
	fd = open("random.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (i++ < 10)
	{
		printf("in main = %s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}
