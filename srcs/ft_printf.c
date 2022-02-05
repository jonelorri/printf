/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:00:26 by jelorria          #+#    #+#             */
/*   Updated: 2022/01/21 19:22:25 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include <stdarg.h>

static int	ft_finder(va_list ap, char c, int i)
{
	if (c == 'c')
		i = i + ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i = i + ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i = i + ft_putstr("0x") + ft_puthex(va_arg(ap, size_t), c);
	else if (c == 'd' || c == 'i')
		i = i + ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		i = i + ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		i = i + ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		i = i + ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			i = ft_finder(ap, *++format, i);
		else
			i = i + ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (i);
}
