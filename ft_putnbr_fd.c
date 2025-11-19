/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:45:53 by marcobenede       #+#    #+#             */
/*   Updated: 2025/11/13 12:49:35 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(int digit, int fd)
{
	char	c;

	c = '0' + digit;
	ft_putchar_fd(c, fd);
}

static void	put_positive(long nb, int fd)
{
	if (nb >= 10)
		put_positive(nb / 10, fd);
	helper(nb % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	put_positive(nb, fd);
}
