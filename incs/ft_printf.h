#ifndef _FUNCIONES_H
#define _FUNCIONES_H

#include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putunbr(unsigned int unbr);
int	ft_puthex(size_t adr, char c);
size_t	ft_strlen(char *str);

#endif
