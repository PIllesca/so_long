/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:25:50 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/12 11:39:00 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	int	e;

	(*i)++;
	e = write(1, &c, 1);
	if (e < 0)
		(*i) = e;
}

void	ft_putstr(char *str, int *i)
{
	int	e;

	if (str != NULL)
	{
		(*i) += ft_strlen(str);
		e = write(1, str, ft_strlen(str));
	}
	else
	{
		(*i) += ft_strlen("(null)");
		e = write(1, "(null)", 6);
	}
	if (e < 0)
		(*i) = e;
}

void	ft_putnbr(int n, int *i)
{
	char			str[13];
	int				j;
	int				temp;
	unsigned int	num;

	j = 0;
	if (n < 0)
		num = -n;
	else
		num = n;
	if (num == 0)
		str[j++] = '0';
	while (num != 0)
	{
		temp = num % 10;
		str[j++] = temp + '0';
		num /= 10;
	}
	if (n < 0)
		str[j++] = '-';
	str[j++] = '\0';
	ft_invstr(str);
	ft_putstr(str, i);
}

void	ft_putnbr_u(unsigned int n, int *i)
{
	unsigned int	temp;
	int				j;
	char			str[12];

	j = 0;
	if (n == 0)
		str[j++] = '0';
	while (n != 0)
	{
		temp = n % 10;
		str[j++] = temp + '0';
		n /= 10;
	}
	str[j++] = '\0';
	ft_invstr(str);
	ft_putstr(str, i);
}
