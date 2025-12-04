/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/04 18:31:43 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *string)
{
	size_t	c;

	if (string == NULL)
		return (0);
	c = 0;
	while (string[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_stash;

	len1 = ft_strlen_gnl(stash);
	len2 = ft_strlen_gnl(buffer);
	new_stash = malloc(len1 + len2 + 1);
	if (new_stash == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_stash[i] = buffer[i - len1];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

int	find_newline(char *stash)
{
	size_t	i;

	if (stash == NULL)
		return (-1);
	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char *stash)
{
	char		*line;
	size_t		i;
	size_t		linelen;

	if (stash == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0' )
		i++;
	if (stash[i] == '\n')
		linelen = i + 1;
	else
		linelen = i;
	line = malloc(linelen + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < linelen)
	{
		line[i] = stash[i];
		i++;
	}
	line[linelen] = '\0';
	return (line);
}

char	*extract_leftover(char *stash)
{
	int		newline;
	char	*leftover;
	int		start;
	int		i;
	int		leftoverlen;

	newline = find_newline(stash);
	if (newline == -1)
		return (NULL);
	start = newline + 1;
	i = start;
	while (stash[i] != '\0')
		i++;
	leftoverlen = i - start;
	if (leftoverlen == 0)
		return (NULL);
	leftover = malloc(leftoverlen + 1);
	if (!leftover)
		return (NULL);
	i = -1;
	while (leftoverlen > ++i)
		leftover[i] = stash[start + i];
	return (leftover[leftoverlen] = '\0', leftover);
}
