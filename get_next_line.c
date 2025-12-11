/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 22:53:22 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (free(s1), NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, (char *)s2, len1 + len2 + 1);
	free(s1);
	return (res);
}

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
		return (free(line), stash[0] = '\0', NULL);
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

/* int main(void)
{
    int     fd = open("test.txt", O_RDONLY);
    char    *line;

    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("LINE: %s", line);
        free(line);
    }
    return (0);
} */