/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:01 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/12 15:51:52 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	left[MAX_FD][BUFFER_SIZE + 1] = {0};
	char		*buf;
	int			check;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	check = 1;
	buf = NULL;
	if (left[fd][0])
	{
		buf = ft_substr(left[fd], 0, BUFFER_SIZE);
		if (!buf)
			return (NULL);
		ft_bzero(left[fd], BUFFER_SIZE + 1);
	}
	while (check > 0 && !ft_strchr(buf, '\n'))
	{
		buf = ft_read(buf, &check, fd);
		if (!buf)
			return (NULL);
	}
	if (ft_len(buf, '\n') < 0 || ft_len(buf, '\n') == ft_len(buf, '\0'))
		return (buf);
	else
		return (ft_sepbuf(buf, left, fd));
}

char	*ft_buffer_alloc(void)
{
	char	*current_read;

	current_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_read)
		return (NULL);
	ft_bzero(current_read, BUFFER_SIZE + 1);
	return (current_read);
}

char	*ft_read(char *buf, int *check, int fd)
{
	char	*current_read;
	char	*temp;

	current_read = ft_buffer_alloc();
	if (!current_read)
		return (ft_free(buf, NULL));
	*check = read(fd, current_read, BUFFER_SIZE);
	if (*check == -1)
		return (ft_free(current_read, buf));
	temp = ft_strjoin(buf, current_read);
	if (buf)
		free(buf);
	buf = ft_substr(temp, 0, ft_len(temp, '\0'));
	ft_free(current_read, temp);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*ft_sepbuf(char *buf, char left[MAX_FD][BUFFER_SIZE + 1], int fd)
{
	char	*line;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_len(buf, '\n');
	line = ft_substr(buf, 0, i);
	if (!line)
		return (ft_free(buf, NULL));
	while (buf[i])
		left[fd][j++] = buf[i++];
	ft_free(buf, NULL);
	return (line);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}
