/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/02 11:01:33 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"
//find string length used in join stash + buffer
size_t	ft_strlen_gnl(const char *string)
{
	size_t	c;

	c = 0;
	if (string == NULL)
		return (NULL);
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