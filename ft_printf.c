/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosaito <kosaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:54:18 by kosaito           #+#    #+#             */
/*   Updated: 2026/11/05 16:58:55 by kosaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		err;

	i = 0;
	count = 0;
	err = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += ft_format(format[i], &args, &err);
		}
		else
			count += ft_putchar(format[i], &err);
		i++;
	}
	va_end(args);
	if (err == -1)
		return (-1);
	return (count);
}

int	ft_format(char spec, va_list *args, int *err)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int), err));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int), err));
	if (spec == '%')
		return (ft_putchar('%', err));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *), err));
	if (spec == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int), err));
	if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), HEX_LOW, err));
	if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), HEX_UP, err));
	if (spec == 'p')
		return (ft_putptr(va_arg(*args, void *), err));
	return (0);
}
