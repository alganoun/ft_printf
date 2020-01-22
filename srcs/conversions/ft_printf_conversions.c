/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:51:49 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:01:53 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft_printf.h"
#include <stdio.h>

void	char_conversion(int x, t_list *flags)
{

	if (flags->flags == 0)
		ft_printf_write(' ', &flags, flags->width - 1);
	ft_printf_write(x, &flags, 1);
	if (flags->flags == '-')
		ft_printf_write(' ', &flags, flags->width - 1);
}

void	str_conversion(char *str, t_list *flags)
{
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precs == YES)
	{
		if (flags->pr_nb == 0)
			len = 0;
		else if (flags->pr_nb < ft_strlen(str) && ft_strlen(str) > 0)
			len = flags->pr_nb;
	}
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
	int diginb;
	int diginb2;

	diginb = ft_digit_nb(x);
	diginb2 = diginb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES && flags->pr_nb >= 0)
			diginb2 = int_conv_prcss(x, &flags, diginb, diginb2);
		else if (flags->width > diginb && flags->flags != '-')
			ft_printf_write(' ', &flags, (flags->width - diginb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			diginb2 = int_conv_prcss(x, &flags, diginb, diginb2);
		else if (flags->width > diginb)
			int_conv_prcss2(x, &flags, diginb);
	}
	if ((x != 0 || flags->precs == NO) && flags->neg == NO)
		ft_putnbr_base(x, flags, "0123456789");
	else if (flags->neg == YES)
		ft_putnbr_base(-x, flags, "0123456789");
	if (flags->flags == '-' && flags->width > diginb2)
		ft_printf_write(' ', &flags, (flags->width - diginb2));
}

void	hexa_conversion(int y, t_list *flags)
{
	int diginb;
	int diginb2;

	diginb = ft_digit_hex_nb(y, &flags, "0123456789abcdef");
	diginb2 = diginb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES && flags->pr_nb >= 0)
			diginb2 = hex_conv_prcss(y, &flags, diginb, diginb2);
		else if (flags->width > diginb && flags->flags != '-')
			ft_printf_write(' ', &flags, (flags->width - diginb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			diginb2 = hex_conv_prcss(y, &flags, diginb, diginb2);
		else if (flags->width > diginb)
			ft_printf_write('0', &flags, (flags->width - diginb));
	}
	if ((y != 0 || flags->precs == NO) && flags->neg == NO)
		ft_putnbr_hexa_base(y, flags, "0123456789abcdef");
	if (flags->flags == '-' && flags->width > diginb2)
		ft_printf_write(' ', &flags, (flags->width - diginb2));
}

void	hexa2_conversion(unsigned int y, t_list *flags)
{
	int diginb;
	int diginb2;

	diginb = ft_digit_hex_nb(y, &flags, "0123456789ABCDEF");
	diginb2 = diginb;
	if (flags->flags == NO || flags->flags == '-')
	{
		if (flags->precs == YES && flags->pr_nb >= 0)
			diginb2 = hex_conv_prcss(y, &flags, diginb, diginb2);
		else if (flags->width > diginb && flags->flags != '-')
			ft_printf_write(' ', &flags, (flags->width - diginb));
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == YES)
			diginb2 = hex_conv_prcss(y, &flags, diginb, diginb2);
		else if (flags->width > diginb)
			ft_printf_write('0', &flags, (flags->width - diginb));
	}
	if ((y != 0 || flags->precs == NO) && flags->neg == NO)
		ft_putnbr_hexa_base(y, flags, "0123456789ABCDEF");
	if (flags->flags == '-' && flags->width > diginb2)
		ft_printf_write(' ', &flags, (flags->width - diginb2));
}
