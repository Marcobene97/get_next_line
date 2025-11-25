/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:37:15 by marcobenede       #+#    #+#             */
/*   Updated: 2025/11/25 17:04:58 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

char	*ft_strjoin(char const *stash, char const *buffer)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*jointstring;

	if (!stash || !buffer)
		return (NULL);
	len1 = ft_strlen(stash);
	len2 = ft_strlen(buffer);
	jointstring = malloc(len1 + len2 + 1);
	if (jointstring == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		jointstring[i] = stash[i];
		i++;
	}
	while (i < len1 + len2)
	{
		jointstring[i] = buffer[i - len1];
		i++;
	}
	jointstring[i] = '\0';
	return (jointstring);
}


/* int main(void)
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
