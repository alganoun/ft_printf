/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:51:49 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 18:12:00 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

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
	unsigned int digit_nb;
	unsigned int digit_nb2;

	digit_nb = ft_digit_nb(x);
	digit_nb2 = digit_nb;
	if (flags->flags == 0)
	{
		if (flags->precs == 1)
		{
			if (flags->pr_nb > digit_nb)
				digit_nb2 = flags->pr_nb;
			if (flags->width > digit_nb2)
				ft_printf_write(' ', &flags, (flags->width - digit_nb2));
			if (flags->pr_nb > digit_nb)
				ft_printf_write('0', &flags, (flags->pr_nb - digit_nb));
		}
		else
		{
			if (flags->width > digit_nb)
				ft_printf_write(' ', &flags, (flags->width - digit_nb));
		}
	}
	else if (flags->flags == '0')
	{
		if (flags->precs == 1)
		{
			if (flags->pr_nb > digit_nb)
				digit_nb2 = flags->pr_nb;
			if (flags->width > digit_nb2)
				ft_printf_write(' ', &flags, (flags->width - digit_nb2));
			if (flags->pr_nb > digit_nb)
				ft_printf_write('0', &flags, (flags->pr_nb - digit_nb));
		}
		else
		{
			if (flags->width > digit_nb)
				ft_printf_write('0', &flags, (flags->width - digit_nb));
		}
	}
	if (x != 0 || flags->precs != 1)
		ft_putnbr_base(x, flags, "0123456789");
}

void	type_selection(int x, char *s, t_list *flags)
{
	if (flags->type == 'c')
		char_conversion(x, flags);
	else if (flags->type == 's')
		str_conversion(s, flags);
	else if (flags->type == 'd' || flags->type == 'i')
		int_conversion(x, flags);
	/*else if (flags->type == 'p')
		adrs_conversion(x, flags);
	else if (flags->type == 'u')
		unsigned_conversion(x, flags);
	else if ((flags->type == 'x') || (flags->type == 'X'))
		hexa_conversion(x, flags);*/
}

