/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:18:20 by jklein            #+#    #+#             */
/*   Updated: 2022/01/27 16:43:03 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		/* -- this part of this process checks the functon status 
		the argument will process the length of each statement --  */

#include "ft_printf.h"

static	void	check(char s, va_list *args, int	*len, int *i)
{
	if (s == 's')
		ft_str(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_nbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_u(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_p(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

		/* -- returning the data type -- */

int	ft_printf(const char	*s, ...)
{
	va_list	ap;
	int		byte;
	int		str;

	byte = 0;
	str = 0;
	va_start(ap, s);
	while (s[byte] != '\0')
	{
		if (s[byte] == '%')
		{
			check(s[++byte], &ap, &str, &byte);
			byte++;
		}
		else
		{
			ft_putchar_len((char)s[byte], &str);
			byte++;
		}
	}
	va_end(ap);
	return (str);
}
