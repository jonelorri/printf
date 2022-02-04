#include "../incs/ft_printf.h"

int	ft_putunbr(unsigned int unbr)
{
	int	i;

	i = 0;
	if (unbr > 9)
		i += ft_putunbr(unbr / 10);
	i += ft_putchar((unbr % 10) + 48);
	return (i);
}
