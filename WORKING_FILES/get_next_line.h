/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:10 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/12 15:40:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for write
# include <stdlib.h> // malloc
# include <limits.h> // NULL
# include <stdint.h> // SIZE_MAX
# include <stdio.h>

# define MAX_FD	1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 56
# endif

char	*ft_buffer_alloc(void);
char	*ft_free(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);
char	*get_next_line(int fd);
char	*ft_read(char *buff, int *check, int fd);
ssize_t	ft_len(const char *s, char c);
char	*ft_strjoin(char *buff, char *read);
char	*ft_split_buff(char *buff, char *leftover);
void	ft_bzero(void *s, size_t n);

#endif