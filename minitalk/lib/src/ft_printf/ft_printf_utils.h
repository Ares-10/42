/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyeongeun <johyeongeun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:27:14 by johyeongeun       #+#    #+#             */
/*   Updated: 2024/02/28 20:27:56 by johyeongeun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int	ft_prf_putchar(char c, int *len);
int	ft_prf_putstr(char *s, int *len);
int	ft_prf_putnbr(int n, int *len);
int	ft_prf_putnbr_1(long n, int *len);
int	ft_prf_itohex(int n, char hex_string[], int *len, int flag);

#endif