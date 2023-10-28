/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:15:14 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/16 21:44:41 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !source)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	while (n--)
		*(d++) = *(s++);
	return (dest);
}
