#include "libft.h"

int	ft_putstr_fd(char *s)
{
	int i;
	int	printed;
	int	aux;

	printed = 0;
	i = 0;
	while (s[i])
	{
		aux = ft_putchar_fd(s[i]);
		if (aux < 0)
			return (-1);
		printed += aux;
		i++;
	}
	return (printed);
}