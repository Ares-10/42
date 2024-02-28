/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:28:58 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 20:51:22 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (*temp == *temp2 && n > 0)
	{
		if (*temp == '\0' || *temp2 == '\0')
		{
			return (0);
		}
		temp++;
		temp2++;
		n--;
	}
	if (n > 0)
		return (*temp - *temp2);
	return (0);
}
