/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 22:53:17 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	lenstr;
	char	*memstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	lenstr = i;
	memstr = malloc(lenstr + 1);
	if (memstr == 0)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		memstr[j] = s[j];
		j++;
	}
	return (memstr);
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	space;

	i = 0;
	while (src[i] != '\0')
		i++;
	j = 0;
	while (dst[j] != '\0' && j < size)
		j++;
	if (j >= size)
		return (size + i);
	space = size - j - 1;
	k = 0;
	while (k < space && src[k] != '\0')
	{
		dst[j + k] = src[k];
		k++;
	}
	if (size > j)
		dst[j + k] = '\0';
	return (j + i);
}
