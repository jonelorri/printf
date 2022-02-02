#include <unistd.h>
#include <stdio.h>

int	ft_putstr(const char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		write(1, &n[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return (0);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
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
		i++;
	return (i);
}

int	ft_putnbr_(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_(nb / 10);
		ft_putnbr_(nb % 10);
	}
	else
		ft_putchar(nb + 48);
		i++;
	return (i);
}

int	ft_putptr (unsigned int ptr)
{
	char	*a;
	int	i;

	a = "0123456789abcdef";
	i = 0;
	if (ptr > 15)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		ft_putchar(a[ptr]);
		i++;
	}
	return (i);
}

int	ft_puthexa(unsigned int nbr)
{
	char *a;
	int i;

	a = "0123456789abcdef";
	i = 0;
	if (nbr > 15)
	{
		ft_puthexa(nbr / 16);
		ft_puthexa(nbr % 16);
	}
	else
	{
		ft_putchar(a[nbr]);
		i++;
	}
	return (1);
}
