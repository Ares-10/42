/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:54:55 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 20:53:40 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*p;
	int		len;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	p = ptr;
	if (!ptr)
		return (0);
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (ptr);
}
