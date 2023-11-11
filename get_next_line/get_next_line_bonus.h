/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:17:30 by hyungcho          #+#    #+#             */
/*   Updated: 2023/11/11 23:27:06 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>

char	*get_next_line(int fd);

char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

void	gnl_lstdelone(t_list *lst, void (*del)(void *));
void	gnl_lstadd_front(t_list **lst, t_list *new);
t_list	*gnl_lstnew(int fd);

#endif
