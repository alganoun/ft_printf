/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:51:49 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:37:05 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

void	char_conversion(int x, t_list *flags)
{
	if (flags->type == 'c')
	{
		if (flags->flags == '-')
			ft_printf_write(' ', &flags, flags->width);
		ft_printf_write(x, &flags, 1);
		if (flags->flags == 0)
			ft_printf_write(' ', &flags, flags->width);
	}
}

void	str_conversion(char *str, t_list *flags)
{
	int len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags->precs > 0)
	{
		len = 0;
		if (flags->pr_nb > 0)
			len = flags->pr_nb;
	}
	else
		len = ft_strlen(str);
	if (flags->flags == '-')
	{
		ft_putstr(str, flags, len);
		ft_printf_write(' ', &flags, flags->width - len);
	}
	else
	{
		ft_printf_write(' ', &flags, flags->width - len);
		ft_putstr(str, flags, len);
	}
}

void	int_conversion(int x, t_list *flags)
{
	size_t digit_nb;
	size_t digit_nb2;

	digit_nb = ft_digit_nb(x);
	digit_nb2 = digit_nb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES)
			digit_nb2 = int_conv_prcss(x, &flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write(' ', &flags, (flags->width - digit_nb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			digit_nb2 = int_conv_prcss(x, &flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write('0', &flags, (flags->width - digit_nb));
	}
	if ((x != 0 || flags->precs == NO || digit_nb2 != digit_nb) && flags->neg == NO)
		ft_putnbr_base(x, flags, "0123456789");
	else if ((flags->precs == NO || digit_nb2 != digit_nb) && flags->neg == YES)
		ft_putnbr_base(-x, flags, "0123456789");
	if (flags->flags == '-' && flags->width > digit_nb2)
		ft_printf_write(' ', &flags, (flags->width - digit_nb2));
}

void	hexa_conversion(int x, t_list *flags)
{
	size_t digit_nb;
	size_t digit_nb2;

	digit_nb = ft_digit_hex_nb(x, &flags, "0123456789abcdef");
	digit_nb2 = digit_nb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES)
			digit_nb2 = hex_conv_prcss(&flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write(' ', &flags, (flags->width - digit_nb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			digit_nb2 = hex_conv_prcss(&flags, digit_nb, digit_nb2);
		else if (flags->width > digit_nb)
			ft_printf_write('0', &flags, (flags->width - digit_nb));
	}
	if ((x != 0 || flags->precs == NO || digit_nb2 != digit_nb) && flags->neg == NO)
		ft_putnbr_base(x, flags, "0123456789abcdef");
	if (flags->flags == '-' && flags->width > digit_nb2)
		ft_printf_write(' ', &flags, (flags->width - digit_nb2));
}
