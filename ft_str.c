/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:37:41 by jklein            #+#    #+#             */
/*   Updated: 2022/01/27 16:49:40 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		/* -- argument will size the string --*/

#include "ft_printf.h"

void	ft_str(char *args, int *len)
{
	size_t	str;

	str = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[str])
	{
		ft_putchar_len(args[str], len);
		str++;
	}
}
