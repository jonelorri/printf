#include <unistd.h>
#include <stdarg.h>

int	ft_char (char c)
{
	return (write (1, &c, 1));
}

int ft_str (char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned int nbr)
{
	char *b;
	int	static count;

	b = "0123456789abcdef";
	count = 0;
	if (nbr > 15)
		ft_hex(nbr / 16);
	count += ft_char(b[nbr % 16]);
	return (count);
}

int	def_arg (char format, va_list arg)
{
	int count;

	count = 0;

	if (format == 's')
		count = ft_str(va_arg(arg, char *));
	if (format =='x')
		count = ft_hex(va_arg(arg, unsigned int));
	return (count);
}

int ft_printf (const char *s, ...)
{
	va_list arg;
	int	count;
	int i;

	va_start(arg, s);
	count = 0;
	i = 0;

	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_char(s[i]);
			i++;
			count++;
		}
		else
		{
			count += def_arg(s[ i + 1], arg);
			i = i + 2;
		
		}
	}
		va_end (arg);
		return (count);
}

int main ()
{
	ft_printf("hola %s\n", "cbustama");
	ft_printf("convierteme este numero 42 que es igual a %x\n", 42);
	return (0);
}



