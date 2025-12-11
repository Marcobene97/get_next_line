/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 20:28:54 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	extract_leftover(char *line, size_t linelen, char *stash)
{
	size_t		j;
	
	j = 0;
	while (line[linelen + j])
		j++;
	if (line[linelen] == '\0')
		stash[0] = '\0';
	else
		ft_strlcpy(&stash[0], line + linelen + 1, j + 1);
}

char	*extract_line(char *line, char *stash)
{
	char		*tmp;
	size_t		i;
	size_t		linelen;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	linelen = i + 1;
	tmp = malloc(linelen + 1);
	if (!tmp)
		return (free(line),stash[0] = '\0', NULL);
	i = -1;
	while (line[++i] && i < linelen)
		tmp[i] = line[i];
	tmp[i] = '\0';
	extract_leftover(line, linelen - 1, stash);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1];
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = ft_strjoin_free(NULL, stash);
	while ((!ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), stash[0] = '\0', NULL);
		stash[bytes_read] = '\0';
		line = ft_strjoin_free(line, stash);
		if (!line)
			return (NULL);
	}
	if (bytes_read == 0 && (!line || line[0] == '\0'))
		return (free(line), stash[0] = '\0', NULL);
	if (ft_strchr(line, '\n'))
		line = extract_line(line, stash);
	return (line);
}
