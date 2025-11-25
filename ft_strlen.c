/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:59:31 by mbenedet          #+#    #+#             */
/*   Updated: 2025/11/25 16:37:11 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

size_t	ft_strlen(const char *string)
{
	size_t	c;

	c = 0;
	while (string[c] != '\0')
	{
		c++;
	}
	return (c);
}

/* int main(void)
{
    int c;
    c = ft_strlen("okfh");
    printf("%d\n", c);
} */
