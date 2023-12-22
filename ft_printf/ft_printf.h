/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:23:54 by hyungcho          #+#    #+#             */
/*   Updated: 2023/12/22 15:45:26 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);

int	ft_prf_putchar(char c, int *len);
int	ft_prf_putstr(char *s, int *len);
int	ft_prf_putnbr(int n, int *len);
int	ft_prf_putnbr_1(long n, int *len);
int	ft_prf_itohex(int n, char hex_string[], int *len, int flag);

#endif