/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:26:06 by wbaali            #+#    #+#             */
/*   Updated: 2024/11/26 13:17:02 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printadress(const unsigned long n)
{
	if (n / 16)
		return (ft_printadress(n / 16) + ft_printadress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char)n - 10 + 'a');
	return (1);
}

int	ft_putpointer(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_printadress((unsigned long)adress));
}
