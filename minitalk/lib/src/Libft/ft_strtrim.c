/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:05:02 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 20:54:43 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	f;
	size_t	b;

	f = 0;
	while (s1[f] && ft_strchr(set, s1[f]))
		f++;
	if (!s1[f])
		return (ft_strdup(""));
	b = ft_strlen(s1) - 1;
	while (s1[b] && ft_strchr(set, s1[b]))
		b--;
	str = (char *)malloc(sizeof(char) * (b - f + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + f, b - f + 2);
	return (str);
}
