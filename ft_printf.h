/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:24:17 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/25 17:23:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		printparam(va_list *pnt, char c);
int		start(const char *s, va_list *pnt);
int		ft_printf(const char *s, ...);

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	rec_putnbr(unsigned int n, int *count);
int		ft_putnbr(int n);

int		ft_putunsigned(unsigned int num);
int		ft_puthexa(unsigned int num, int *count);
int		ft_putcaphexa(unsigned int num, int *count);
int		putunsignedhexa(unsigned long num, int *count);
int		ft_putpnt(void *pnt);

#endif
