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

void	ft_putptr(void *ptr)
{
	write(1, ptr, 10);
}

void	ft_putstr(const char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		write(1, &n[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

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
			if (format[i] == 'p')
				ft_putptr(va_arg(ap, void *));
			i++;
		}
		write(1, &format[i] , 1);
		i++;
	}
   return(i);
}

int	main(){
	char	x[5] = {"hola"};
	int		i;
	char	a;
	void *ptr;

	a = '1';
	i = 115;
	ptr = &a;
	ft_printf("El valor %% de a es: %c y el de i es: %d\n", a, i);
	ft_printf("El valor de x es: %s\nEl valor de ptr es: %p", x, ptr);
	return(0);
}
