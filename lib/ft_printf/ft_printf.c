/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:56:49 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/10 21:31:46 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_format(char c, va_list args, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (c == '%')
		ft_putchar('%', i);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int), i);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, int), i);
	else if (c == 'x')
		ft_puthex(va_arg(args, int), i);
	else if (c == 'X')
		ft_putuhex(va_arg(args, int), i);
	else if (c == 'p')
		ft_putmhex(va_arg(args, void *), i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str, &i);
			if (i < 0)
				break ;
		}
		else
		{
			str++;
			chk_format(*str, args, &i);
		}
		str++;
	}
	va_end(args);
	return (i);
}
