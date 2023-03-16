#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);

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
