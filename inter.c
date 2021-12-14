/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:35:54 by clesaffr          #+#    #+#             */
/*   Updated: 2021/12/14 14:44:05 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	static int	i;
	static int	j;
	static int	ascii[256];

	if (ac == 3)
	{
		i = 0;
		while (i < 256)
			ascii[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && ascii[(unsigned char)av[i][j]] == 0)
					ascii[(unsigned char)av[i][j]] = 1;
				else if (i == 1 && ascii[(unsigned char)av[i][j]] == 1)
				{
					write(1, &av[i][j], 1);
					ascii[(unsigned char)av[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
