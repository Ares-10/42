/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:18:18 by hyungcho          #+#    #+#             */
/*   Updated: 2023/10/28 21:43:46 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, int len)
{
	char	*str;

	if (len == 0)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

char	**ft_freeall(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

int	ft_wordcount(char const *s, char c)
{
	int	word_count;
	int	len;
	int	i;

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

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		k;
	int		len;

	strs = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	k = 0;
	while (i < ft_wordcount(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		len = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		strs[i] = ft_strndup(&s[len], k - len);
		if (strs[i++] == 0)
			return (ft_freeall(strs));
	}
	strs[i] = NULL;
	return (strs);
}
