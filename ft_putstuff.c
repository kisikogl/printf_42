/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:13:38 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/25 16:30:21 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write (1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	rec_putnbr(unsigned int n, int *count)
{
	if (n != 0)
	{
		rec_putnbr(n / 10, count);
		ft_putchar(n % 10 + '0');
		(*count)++;
	}
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
	}
	if (n == 0)
	{
		count += ft_putchar('0');
	}
	else
	{
		rec_putnbr(n, &count);
	}
	return (count);
}
