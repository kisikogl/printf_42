/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:39:22 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/25 17:08:10 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printparam(va_list *pnt, char c)
{
	int	count;

	count = 1;
	if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (c == 'c')
		return (ft_putchar(va_arg(*pnt, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*pnt, char *)));
	if (c == 'p')
		return (ft_putpnt(va_arg(*pnt, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*pnt, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(*pnt, unsigned int)));
	if (c == 'x')
		return (ft_puthexa(va_arg(*pnt, unsigned int), &count));
	if (c == 'X')
		return (ft_putcaphexa(va_arg(*pnt, unsigned int), &count));
	return (-1);
}

int	start(const char *s, va_list *pnt)
{
	int	count;
	int	temp;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != '%')
		{
			count += ft_putchar(s[i]);
		}
		else
		{
			i++;
			temp = printparam(pnt, s[i]);
			if (temp == -1)
				return (0);
			count += temp;
		}
		i++;
	}
	va_end(*pnt);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	va_list	*appnt;

	va_start(ap, s);
	appnt = &ap;
	return (start(s, appnt));
}
