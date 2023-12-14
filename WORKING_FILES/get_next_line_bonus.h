/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:10 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/12 15:49:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> // for write
# include <stdlib.h> // malloc
# include <limits.h> // NULL
# include <stdint.h> // SIZE_MAX

# define MAX_FD	1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 56
# endif

char	*ft_buffer_alloc(void);
char	*ft_free(char *s1, char *s2);
char	*ft_read(char *buf, int *check, int fd);
char	*ft_sepbuf(char *buf, char left[MAX_FD][BUFFER_SIZE + 1], int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *buf, char *read);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);
char	*get_next_line(int fd);
ssize_t	ft_len(const char *s, char c);
void	ft_bzero(void *s, size_t n);

#endif