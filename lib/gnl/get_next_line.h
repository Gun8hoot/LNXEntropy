/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:11:52 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/14 07:42:42 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(FILE *stream);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strdup(const char *s);
size_t	ft_gnl_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);

#endif
