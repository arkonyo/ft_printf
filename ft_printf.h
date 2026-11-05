/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosaito <kosaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:39:56 by kosaito           #+#    #+#             */
/*   Updated: 2026/11/05 16:48:55 by kosaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_putchar(char c, int *err);
int	ft_format(char spec, va_list *args, int *err);
int	ft_putnbr(long n, int *err);
int	ft_putstr(char *s, int *err);
int	ft_puthex(unsigned long n, char *base, int *err);
int	ft_putptr(void *p, int *err);
#endif
