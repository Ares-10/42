/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:04:21 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 20:50:04 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	dest_l;
	size_t	src_l;

	s = dstsize;
	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	while (*dst != '\0' && s > 0)
	{
		dst++;
		s--;
	}
	if (s == 0)
		return (src_l + dstsize);
	while (*src != '\0' && --s > 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (src_l + dest_l);
}
