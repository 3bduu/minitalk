/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:55:31 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/07 18:50:23 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(int c, int *len);
void	ft_put_hex_min_nbr(unsigned int n, int *len);
void	ft_put_hex_maj_nbr(unsigned int n, int *len);
void	ft_put_address(unsigned long n, int *len);
void	ft_put_sign(int c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_put_uns_nbr(unsigned int n, int *len);
int		ft_printf(const char *print, ...);
#endif
