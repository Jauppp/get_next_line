/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:10 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/12/08 14:53:17 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for write
# include <stdlib.h> // malloc
# include <limits.h> // NULL
# include <stdio.h> // to remove
# include <strings.h> // for bzero

# define MAX_FD	1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_len(const char *s, char c);
char	*ft_free_all(char **current_read, char **left);
char	*ft_sep_buffer(char **left);
char	*ft_line_no_leftovers(char **left);
char	*ft_join_leftovers(char *current_read, char **left);
char	*ft_buffer_alloc(void);

#endif