/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:48:12 by abenlahb          #+#    #+#             */
/*   Updated: 2022/11/08 02:48:07 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_types(va_list args, char c)
{
	int	lenght;

	lenght = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int), &lenght);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &lenght);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), &lenght);
	else if (c == 'u')
		ft_put_uns_nbr(va_arg(args, unsigned int), &lenght);
	else if (c == 'x')
		ft_put_hex_min_nbr(va_arg(args, unsigned int), &lenght);
	else if (c == 'X')
		ft_put_hex_maj_nbr(va_arg(args, unsigned int), &lenght);
	else if (c == 'p')
		ft_put_address(va_arg(args, unsigned long), &lenght);
	else if (c == '%')
		ft_putchar('%', &lenght);
	return (lenght);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		len_type;
	int		i;

	len_type = 0;
	i = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%' && print[i + 1] != '\0')
		{
			len_type += len_types(args, print[i + 1]);
			i++;
		}
		else if (print[i] != '%')
			ft_putchar(print[i], &len_type);
		i++;
	}
	va_end(args);
	return (len_type);
}
