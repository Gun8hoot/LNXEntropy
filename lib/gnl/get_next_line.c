/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:27:07 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/13 09:37:10 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_next(char *static_vars)
{
	char	*first_next_letter;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (static_vars[i] && static_vars[i] != '\n')
		i++;
	first_next_letter = malloc(sizeof(char) * (ft_strlen(static_vars) - i + 1));
	if (!first_next_letter)
		return (NULL);
	if (static_vars[i] == '\n')
		i++;
	while (static_vars[i])
	{
		first_next_letter[j] = static_vars[i];
		i++;
		j++;
	}
	first_next_letter[j] = '\0';
	free(static_vars);
	return (first_next_letter);
}

char	*ft_safe_dup(char *static_vars)
{
	char	*line;

	if (!static_vars || !static_vars[0])
		return (NULL);
	line = ft_gnl_strdup(static_vars);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_readnstock(FILE *stream, char *static_vars)
{
	char	*buffer;
	ssize_t	bytes;

	bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_gnl_strchr(static_vars, '\n') && bytes > 0)
	{
		bytes = fread(buffer, sizeof(char), BUFFER_SIZE, stream);
		if (bytes < 0)
		{
			if (static_vars)
				free(static_vars);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		static_vars = ft_gnl_strjoin(static_vars, buffer);
	}
	free(buffer);
	return (static_vars);
}

char	*get_next_line(FILE *stream)
{
	static char	*static_vars;
	char		*line;

	if (stream == NULL || BUFFER_SIZE <= 0)
	{
		free(static_vars);
		return (NULL);
	}
	static_vars = ft_readnstock(stream, static_vars);
	if (!static_vars || !static_vars[0])
	{
		if (static_vars)
			free(static_vars);
		return (static_vars = NULL, NULL);
	}
	line = ft_safe_dup(static_vars);
	static_vars = ft_extract_next(static_vars);
	return (line);
}
