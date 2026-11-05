/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosaito <kosaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:14:52 by kosaito           #+#    #+#             */
/*   Updated: 2026/11/03 18:44:48 by kosaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *err)
{
	if (write(1, &c, 1) == -1)
	{
		*err = -1;
		return (-1);
	}
	return (1);
}

int	ft_putnbr(long n, int *err)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-', err);
		n = n * -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10, err);
	}
	count += ft_putchar(n % 10 + '0', err);
	return (count);
}

int	ft_putstr(char *s, int *err)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)", err));
	while (s[i] != '\0')
	{
		ft_putchar(s[i], err);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, char *base, int *err)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, base, err);
	}
	count += ft_putchar(base[n % 16], err);
	return (count);
}

int	ft_putptr(void *p, int *err)
{
	int	count;

	if (p == NULL)
		return (ft_putstr("(nil)", err));
	count = ft_putstr("0x", err);
	count += ft_puthex((unsigned long) p, "0123456789abcdef", err);
	return (count);
}
