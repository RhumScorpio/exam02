#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
void	ft_string(char *str, int *len)
{
	int i;
	
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	*len += write(1, str, i);
}

void	ft_putnbr(long long int nb, int nba, int *len)
{
	char *base = "0123456789abcdef";
	unsigned int hel = 0;

	if (nb < 0)
	{
		hel = -nb;
		if (nba == 10)
			*len += write(1, "-", 1);
	}
	else
		hel = nb;
	if (hel >= nba)
		ft_putnbr((hel / nba), nba, len);
	*len += write(1, &base[hel % nba], 1);
}

int	ft_printf(const char *str, ...)
{
	int len;
	int	i;
	va_list va;

	i = 0;
	len = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == '%')
				len += write(1, "%", 1);
			if (str[i] == 's')
				ft_string(va_arg(va, char *), &len);
			if (str[i] == 'd')
				ft_putnbr((long long int)va_arg(va, int), 10, &len);
			if (str[i] == 'x')
				ft_putnbr((long long int)va_arg(va, unsigned int), 16, &len);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(va);
	return (len);
}

int main()
{
	char *s = NULL;
	char *s2 = "toto";
	int i = INT_MIN;
	int	x = INT_MAX;
	unsigned int a = UINT_MAX;
	int i2 = 80000000;
	int i3 = 0;
	int ret = 0;
	int ret2 = 0;
	
	ret = ft_printf("Hello %s, how old is %d? It's %x.\n", s, i, x);
	ret2 = printf("Hello %s, how old is %d? It's %x.\n", s, i, x);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("-----%%eeeepoapeoje\n");
	ret2 = printf("-----%%eeeepoapeoje\n");
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("-%x%x%d%x%d-%s%s%s'\n", i, x, a, a, i, s, s2, s);
	ret2 = printf("-%x%x%d%x%d-%s%s%s'\n", i, x, a, a, i, s, s2, s);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("%x\n", x);
	ret2 = printf("%x\n", x);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("%x\n", i);
	ret2 = printf("%x\n", i);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("-%d%d\n", i3, i2);
	ret2 = printf("-%d%d\n", i3, i2);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("%d\n", x);
	ret2 = printf("%d\n", x);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("%d\n", i);
	ret2 = printf("%d\n", i);
	printf("%d | %d\n", ret, ret2);
	ret = ft_printf("%x\n", a);
	ret2 = printf("%x\n", a);
	printf("%d | %d\n", ret, ret2);
	return (0);
}
