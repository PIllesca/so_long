/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:17:33 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/12 11:37:17 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(int num, int *i)
{
	char	str[20];

	ft_inthex(num, str);
	ft_putstr(str, i);
}

void	ft_putuhex(int num, int *i)
{
	char	str[20];

	ft_inthex(num, str);
	to_upper(str);
	ft_putstr(str, i);
}

void	ft_putmhex(void *p, int *i)
{
	char	str[20];

	ft_sizethex((size_t)p, str);
	ft_putstr(str, i);
}
