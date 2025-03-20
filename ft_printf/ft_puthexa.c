/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:33:19 by wbaali            #+#    #+#             */
/*   Updated: 2024/11/26 13:17:30 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(char form, long double nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = NULL;
	if (form == 'x')
		hex = "0123456789abcdef";
	if (form == 'X')
		hex = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr >= 16)
		count += ft_puthexa(form, (nbr / 16));
	count += ft_putchar(hex[(unsigned long)nbr % 16]);
	return (count);
}
