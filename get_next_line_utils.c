/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/02 19:03:42 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"
//find string length used in join stash + buffer
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
//join stash and buffer together - review line 47 logic
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
//find newline in stash
int find_newline(char *stash)
{
	size_t	i;

	if (stash == NULL)
		return (-1);
	i = 0;
	while(stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//Line extraction helper
char *extract_line(char *stash)
{
	char		*line;
	int			i;
	size_t		linelen;

	if (stash == NULL)
		return(NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0' )
		i++;
	if (stash[i] == '\n')
		linelen = i + 1;
	else
		linelen = i; 
	line = malloc(linelen + 1);
	i = 0;
	while (i < linelen)
	{
		line[i] = stash[i];
		i++;
	}
	line[linelen] = '\0';
	return (line);
}
char *extract_leftover(char *stash)
{
	int		newline;
	char	*leftover;
	int 	start;
	int		i;
	int		leftoverLen;
	
	newline = find_newline(stash);
	if (newline == -1)
		return (NULL);
	start = newline + 1;
	i = start;
	while (stash[i] != '\0')
		i++;
	leftoverLen = i - start;
	leftover = malloc(leftoverLen + 1);
	i = 0;
	while (leftoverLen > i)
	{
		leftover[i] = stash[start + i];
		i++;
	}
	leftover[leftoverLen] = '\0';
	return (leftover);
}


/* 
Line extraction with commentary
//Line extraction helper
char *extract_line(char *stash)
{
	char		*line;
	int			i;
	size_t		linelen;

	if (stash == NULL)
		return(NULL);

	// 1. Count until newline or end
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;

	// 2. Compute line length
	if (stash[i] == '\n')
		linelen = i + 1;   // includes newline
	else
		linelen = i;       // no newline

	// 3. Allocate
	line = malloc(linelen + 1);

	// 4. Copy characters
	i = 0;
	while (i < linelen)
	{
		line[i] = stash[i];
		i++;
	}

	// 5. Null terminate
	line[linelen] = '\0';

	return (line);
}


*/


//Testing helpers in isolation
/* int main(void)
{
    char *stash = strdup("Hello");
    char *buffer = strdup("World");
    char *joined = ft_strjoin_gnl(stash, buffer);

    printf("%s\n", joined);
} */

/* int main(void)
{
	char *s1 = "Hello\nWorld";
	char *s2 = "\nStart";
	char *s3 = "NoNewLineHere";

	printf("s1 --> %d\n", find_newline(s1));
	printf("s1 --> %d\n", find_newline(s2));
	printf("s1 --> %d\n", find_newline(s3));
} */

/* 
// Strjoin test 
int main(void)
{
	char const *s1;
	char const *s2;
	char *joint;

	s1 = "Marco";
	s2 = "Benedettelli";
	joint = ft_strjoin(s1, s2);
	printf("%s\n", joint);
	free(joint);
} */