/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:23:54 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/19 20:13:45 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);

void	ft_prf_putchar(char c, int *len);
void	ft_prf_putstr(char *s, int *len);
void	ft_prf_putnbr(int n, int *len);
void	ft_prf_putnbr_1(long n, int *len);
void	ft_prf_itohex(int n, int *len, int flag);

#endif