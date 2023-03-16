/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:39:50 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/16 12:47:26 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	static int	i;
	static int	j;
	static char	ascii[256];
	
	if (ac == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
				while (av[i][j])
				{
					if (!(ascii[(unsigned char)av[i][j]]))
					{
						write(1, &av[i][j], 1);
						ascii[(unsigned char)av[i][j]] = 1;
					}
					j++;
				}
				i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

