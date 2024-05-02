/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:52:04 by pillesca          #+#    #+#             */
/*   Updated: 2023/09/22 12:41:58 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Función que copia n bytes de la cadena src a dst y devuelve un puntero a dst.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*str;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr = dst;
	str = (char *)src;
	while (n--)
		*ptr++ = *str++;
	return (dst);
}
