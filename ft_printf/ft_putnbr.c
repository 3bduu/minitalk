/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:12:30 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/07 18:46:51 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
		ft_putnbr(n, len);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10, len);
		ft_putchar(((n % 10) + '0'), len);
	}
}
