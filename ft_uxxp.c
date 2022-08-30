/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:41:23 by jklein            #+#    #+#             */
/*   Updated: 2022/01/27 17:12:31 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

		/* -- this process will controll the unsigned varabels -- */

void	ft_u(unsigned int u, int *len)
{
	int		num;
	char	*base_char;
	char	str[25];

	base_char = "0123456789";
	num = 0;
	if (u == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (u != 0)
	{
		str[num] = base_char[u % 10];
		u /= 10;
		num++;
	}
	while (num--)
		ft_putchar_len(str[num], len);
}

		/* -- the base charactor is definded here -- */

void	ft_hex(unsigned int x, int *len, char hex)
{
	int		num;
	char	*base_char;
	char	str[25];

	if (hex == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	num = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[num] = base_char[x % 16];
		x /= 16;
		num++;
	}
	while (num--)
		ft_putchar_len(str[num], len);
}

		/* -- controlles the size output of the process -- */	

void	ft_p(size_t	p, int	*len)
{
	int		num;
	char	*base_char;
	char	str[25];

	base_char = "0123456789abcdef";
	num = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (p == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (p != 0)
	{
		str[num] = base_char[p % 16];
		p /= 16;
		num++;
	}
	while (num--)
		ft_putchar_len(str[num], len);
}
