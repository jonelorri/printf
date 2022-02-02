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

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(const char *n);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr_(int nb);
int	ft_putptr(unsigned int ptr);
int	ft_puthexa(unsigned int nbr);

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	char	p;

	p = '%';
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(ap, char *));
			if (format[i] == 'd')
				ft_putnbr(va_arg(ap, int));
			if (format[i] == 'c')
				ft_putchar(va_arg(ap, int));
			if (format[i] == '%')
				write(1, &p, 1);
			if (format[i] == 'u')
				ft_putnbr_(va_arg(ap, int));
			if (format[i] == 'x')
				ft_puthexa(va_arg(ap, unsigned int));
			if (format[i] == 'p')
				write(1, "0x", 2);
				ft_putptr(va_arg(ap, unsigned int));
			i++;
		}
		write(1, &format[i] , 1);
		i++;
	}
	return(i);
}

int	main(){
	char	x[5] = {"hola"};
	int	i;
	char	a;
	void 	*ptr;

	a = '1';
	i = 115;
	ptr = &a;	
	ft_printf("El valor de ptr es: %p\n", ptr);
	printf("puntero bueno: %p", ptr);
	return(0);
}
