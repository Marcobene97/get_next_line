/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 19:30:51 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Malloc helper
Pass the size_tPass string specifiying which fial and succeed
Static variable in malloc
 */

 char	*ft_strdup(const char *src)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}

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
		return (free(stash), NULL);
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

char	*ft_strchr(const char *s, int c)
{
	const char		*p;
	unsigned char	u;

	p = s;
	u = (unsigned char)c;
	while (*p)
	{
		if (*p == (unsigned char) u)
			return ((char *)p);
		p++;
	}
	if (u == '\0')
		return ((char *)p);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenstr;

	i = 0;
	while (src[i] != '\0')
		i++;
	lenstr = i;
	if (size == 0)
		return (lenstr);
	i = 0;
	while (i < size - 1 && i < lenstr)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lenstr);
}




	// if (leftoverlen == 0)
	// 	return (NULL);