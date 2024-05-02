/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:29 by pillesca          #+#    #+#             */
/*   Updated: 2024/04/12 11:35:59 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_invstr(char *str);
size_t	ft_strlen(const char *str);
void	to_upper(char *str);
void	ft_inthex(unsigned int num, char *str);
void	ft_puthex(int num, int *i);
void	ft_putuhex(int num, int *i);
void	ft_putmhex(void *p, int *i);
void	ft_sizethex(size_t num, char *str);
void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i);
void	ft_putnbr(int n, int *i);
void	ft_putnbr_u(unsigned int n, int *i);
int		ft_printf(char const *str, ...);

#endif
