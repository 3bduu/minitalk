/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_maj_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:07:14 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/07 18:46:43 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex_maj_nbr(unsigned int n, int *len)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_put_hex_maj_nbr(n / 16, len);
	ft_putchar(hex[n % 16], len);
}
