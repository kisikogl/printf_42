/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmorestuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:09 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/20 17:17:55 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		count++;
	}
	else
		rec_putnbr(num, &count);
	return (count);
}

int	ft_puthexa(unsigned int num, int *count)
{
	if (num != 0)
	{
		*count = 0;
		ft_puthexa(num / 16, count);
		num = num % 16;
		if (num > 9)
			num += 87;
		else
			num += '0';
		ft_putchar(num);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0');
	return (*count);
}

int	ft_putcaphexa(unsigned int num, int *count)
{
	if (num != 0)
	{
		*count = 0;
		ft_putcaphexa(num / 16, count);
		num = num % 16;
		if (num > 9)
			num += 55;
		else
			num += '0';
		ft_putchar(num);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0');
	return (*count);
}

int	putunsignedhexa(unsigned long num, int *count)
{
	if (num != 0)
	{
		*count = 0;
		putunsignedhexa(num / 16, count);
		num = num % 16;
		if (num > 9)
			num += 87;
		else
			num += '0';
		ft_putchar(num);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0');
	return (*count);
}

int	ft_putpnt(void *pnt)
{
	int	count;

	count = 1;
	ft_putstr("0x");
	putunsignedhexa((unsigned long)pnt, &count);
	count += 2;
	return (count);
}
