/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:18:18 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/26 18:37:09 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	w_count(char const *s, char c);
char	*fun(const char *s, size_t len);

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**strs;
	size_t	strs_i;

	strs = (char **)malloc(sizeof(char *) * (w_count(s, c) + 1));
	if (!strs)
		return (0);
	len = 0;
	strs_i = 0;
	while (*s)
	{
		if (*s++ == c)
		{
			if (len)
				strs[strs_i++] = fun(s - 1, len);
			len = 0;
		}
		else
			len++;
	}
	if (len)
		strs[strs_i++] = fun(s, len);
	strs[strs_i] = 0;
	return (strs);
}

char	*fun(const char *s, size_t len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	ft_memcpy(str, s - len, len);
	str[len] = '\0';
	return (str);
}

size_t	w_count(char const *s, char c)
{
	size_t	word_count;
	size_t	len;
	int		i;

	i = 0;
	word_count = 0;
	len = 0;
	while (s[i])
	{
		if (s[i++] == c)
		{
			if (len)
				word_count++;
			len = 0;
		}
		else
			len++;
	}
	if (len)
		word_count++;
	return (word_count);
}
