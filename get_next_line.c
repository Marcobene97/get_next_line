/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco_linux <marco_linux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/07 04:24:05 by marco_linux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
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
}

//	if (BUFFER_SIZE <= 0 || fd < 0)
//		return (NULL);
// 	char			*leftover;
// 	if (BUFFER_SIZE <= 0 || fd < 0)
//		return (NULL);
// return (statement1 , statement2 , statement3 , ... + n , returned statement);
// int main(void)
// {
// 	int fd;
// 	char *line;
// 	fd = open("test.txt", O_RDONLY);
// 	//error checking
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }