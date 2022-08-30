/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:16:31 by jklein            #+#    #+#             */
/*   Updated: 2022/01/27 16:43:47 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

		/* -- the length in a number allocated
	* there is no assigned variable for the body --*/

void	ft_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_nbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}
