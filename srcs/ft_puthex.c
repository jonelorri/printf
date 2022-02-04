#include "../incs/ft_printf.h"

int	ft_puthex(size_t adr, char  c)
{
	char	*a;
	char	*b;
	int 	i;

	a = "0123456789abcdef";
	b = "0123456789ABCDEF";
	i = 0;
	if (c == 'x' || c == 'p')
	{
		if (adr >= 16)
			i += ft_puthex(adr / 16, c);
		i += ft_putchar(a[adr % 16]);
		return (i);
	}
	if (c == 'X')
	{
		if (adr >= 16)
			i += ft_puthex(adr / 16, c);
		i += ft_putchar(b[adr % 16]);
		return (i);
	}
	return (0);
}
