/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 19:33:55 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	extract_leftover(char *line, size_t linelen, char *stash)
{
	size_t		j;
	
	j = 0;
	while (line[linelen + j])
		j++;
	if (line[linelen])
		stash[0] = '\0';
	else
		ft_strlcpy(&stash[0], line + linelen, j + 1);
}

char	*extract_line(char *line, char *stash)
{
	char		*tmp;
	size_t		i;
	size_t		linelen;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0' )
		i++;
	if (line[i] == '\n')
		linelen = i + 1;
	else
		linelen = i;
	tmp = malloc(linelen + 1);
	if (!tmp)
		return (free(line),stash[0] = '\0', NULL);
	i = -1;
	while (++i < linelen)
		tmp[i] = line[i];
	tmp[linelen] = '\0';
	extract_leftover(line, linelen, stash);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1];
	char			*line;
	ssize_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	line = ft_strjoin_gnl(NULL, stash);
	while (bytes_read > 0 && !(ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), stash[0] = '\0', NULL);
		line[bytes_read] = '\0';
		line = ft_strjoin_gnl(line, stash);
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
	int fd;
	char *line;
	fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);free(): double
	}
	close(fd);
	return (0);
} */

//	if (!line)
//		return (free(buffer), free(stash), stash = NULL, buffer = NULL, NULL);	
// if (BUFFER_SIZE <= 0 || fd < 0)
//		return (NULL);
// 	char			*leftover;
// 	if (BUFFER_SIZE <= 0 || fd < 0)
//		return (NULL);
// return (statement1 , statement2 , statement3 , ... + n , returned statement);

/* char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	char			*line;
	char			*leftover;
	ssize_t			bytes_read;

	buffer = NULL;
	bytes_read = 1;
	if (!stash && bytes_read == 0)
		return (NULL);
	while (bytes_read > 0 && (find_newline(stash) == -1 || !stash))
	{
		if (!buffer)
		{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), stash = NULL, NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	if (!stash || stash[0] == '\0')
		return (free(buffer), free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	leftover = extract_leftover(stash);
	return (free(stash), stash = leftover, free(buffer), line);
} */
/* char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	char			*line;
	char			*leftover;
	ssize_t			bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (find_newline(stash) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), stash = NULL, NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	if (!stash || stash[0] == '\0')
		return (free(buffer), free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	leftover = extract_leftover(stash);
	return (free(stash), stash = leftover, free(buffer), line);
} */
/* char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	char		*left;
	ssize_t		r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = NULL;
	r = 1;
	while (r > 0 && (!stash || find_newline(stash) == -1))
	{
		if (!buf && !(buf = malloc(BUFFER_SIZE + 1)))
			return (NULL);
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		if (r == 0)
			break ;
		buf[r] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	if (!stash || stash[0] == '\0')
		return (free(buf), free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	left = extract_leftover(stash);
	free(stash);
	free(buf);
	return (stash = left, line);
} */
// return (statement1 , statement2 , statement3 , ... + n , returned statement);

/* malloc ( || (line[i] == "\n") + 2)

if (line[i] == "\n")
 */

/*  int main(void)
{
	int fd = open("multiple_nl.txt", O_RDONLY);
	char *line;
	int i = 1;
	
	while ((line = get_next_line(fd)))
	{
		printf("Line %d: [%s]\n", i++, line);
		free(line);
	}
	close(fd);
	return 0;
} */