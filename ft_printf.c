/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:30:46 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/30 02:30:51 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
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
