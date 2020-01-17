/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions2.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 15:35:47 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:28:31 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

void	adrs_conversion(void *z, t_list *flags)
{
	unsigned long	y;
	size_t 			digit_nb;
	size_t			digit_nb2;

	y = (unsigned long)z;
	digit_nb = ft_adrs_digit_nb(y, &flags, "0123456789abcdef");
	digit_nb2 = digit_nb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES)
			digit_nb2 = adrs_conv_prcss(&flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write(' ', &flags, (flags->width - digit_nb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			digit_nb2 = adrs_conv_prcss(&flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write('0', &flags, (flags->width - digit_nb));
	}
	ft_printf_write('0', flags, 1);
	ft_printf_write('x', flags, 1);
	ft_putnbr_adrs_base(y, &flags, "0123456789abcdef");
	if (flags->flags == '-' && flags->width > digit_nb2)
		ft_printf_write(' ', &flags, (flags->width - digit_nb2));
}
