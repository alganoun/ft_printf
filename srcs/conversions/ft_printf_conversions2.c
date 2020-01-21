/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions2.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 15:35:47 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:27:08 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft_printf.h"

void	pourcent_conversion(t_list *flags)
{
	if (flags->flags == 0)
		ft_printf_write(' ', &flags, flags->width - 1);
	else if (flags->flags == '0')
		ft_printf_write('0', &flags, flags->width - 1);
	ft_printf_write('%', &flags, 1);
	if (flags->flags == '-')
		ft_printf_write(' ', &flags, flags->width - 1);
}

void	unsigned_conversion(unsigned int y, t_list *flags)
{
	int digit_nb;
	int digit_nb2;

	digit_nb = ft_unsigned_digit_nb(y);
	digit_nb2 = digit_nb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES)
			digit_nb2 = int_conv_prcss(y, &flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb && flags->flags != '-')
			ft_printf_write(' ', &flags, (flags->width - digit_nb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			digit_nb2 = int_conv_prcss(y, &flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write('0', &flags, (flags->width - digit_nb));
	}
	if (y != 0 || flags->precs == NO || digit_nb2 != digit_nb)
		ft_unsigned_putnbr_base(y, flags, "0123456789");
	if (flags->flags == '-' && flags->width > digit_nb2)
		ft_printf_write(' ', &flags, (flags->width - digit_nb2));
}

void	adrs_conversion(void *z, t_list *flags)
{
	unsigned long	y;
	int				digit_nb;
	int				digit_nb2;

	y = (unsigned long)z;
	digit_nb = ft_adrs_digit_nb(y, &flags, "0123456789abcdef");
	if (z == NULL && flags->precs == YES)
		digit_nb--;
	digit_nb2 = digit_nb;
	if (flags->flags == NO)
	{
		if (flags->precs == YES)
			digit_nb2 = adrs_conv_prcss(&flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write(' ', &flags, (flags->width - digit_nb));
	}
	ft_printf_write('0', &flags, 1);
	ft_printf_write('x', &flags, 1);
	if(flags->precs != YES || z != NULL)
		ft_putnbr_adrs_base(y, &flags, "0123456789abcdef");
	if (flags->flags == '-' && flags->width > digit_nb2)
		ft_printf_write(' ', &flags, (flags->width - digit_nb2));
}
