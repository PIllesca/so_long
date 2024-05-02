/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:03:55 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/12 11:37:52 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*str)
	{
		str++;
	}
	return (str - ptr);
}

void	to_upper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
		str++;
	}
}

void	ft_invstr(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) -1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

void	ft_inthex(unsigned int num, char *str)
{
	int	temp;
	int	j;

	j = 0;
	if (num == 0)
		str[j++] = '0';
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			str[j++] = temp + '0';
		else
			str[j++] = temp -10 + 'a';
		num /= 16;
	}
	str[j++] = '\0';
	ft_invstr(str);
}

void	ft_sizethex(size_t num, char *str)
{
	size_t	temp;
	size_t	j;

	j = 0;
	if (num == 0)
		str[j++] = '0';
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			str[j++] = temp + '0';
		else
			str[j++] = temp -10 + 'a';
		num /= 16;
	}
	str[j++] = 'x';
	str[j++] = '0';
	str[j++] = '\0';
	ft_invstr(str);
}
