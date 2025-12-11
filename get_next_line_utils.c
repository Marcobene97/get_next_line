/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:49 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/11 19:49:19 by mbenedet         ###   ########.fr       */
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



char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (dst[j] && j < dstsize)
		j++;
	len = i + j;
	if (dstsize <= j)
		return (len);
	i = 0;
	while (src[i] && i < (dstsize - j - 1))
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (len);
}
char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (free(s1), NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcat(res, (char *)s2, len_s1 + len_s2 + 1);
	free(s1);
	return (res);
}
