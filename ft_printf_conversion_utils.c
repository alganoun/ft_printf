/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion_utils.c                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 12:14:40 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 16:23:29 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

int	int_conv_prcss(int x, t_list **flags, size_t digit_nb, size_t digit_nb2)
{
	if ((*flags)->pr_nb > digit_nb)
		digit_nb2 = (*flags)->pr_nb;
	if (x < 0)
		digit_nb2 = digit_nb2 + 1;
	if ((*flags)->width > digit_nb2 && ((*flags)->flags == NO
			|| (*flags)->flags == '0'))
		ft_printf_write(' ', flags, ((*flags)->width - digit_nb2));
	if (x < 0)
	{
		ft_printf_write('-', flags, 1);
		(*flags)->neg = YES;
	}
	if ((*flags)->pr_nb > digit_nb)
		ft_printf_write('0', flags, ((*flags)->pr_nb - digit_nb));
	return (digit_nb2);
}

int		hex_conv_prcss(t_list **flags, size_t digit_nb, size_t digit_nb2)
{
	if ((*flags)->pr_nb > digit_nb)
		digit_nb2 = (*flags)->pr_nb;
	if ((*flags)->width > digit_nb2 && ((*flags)->flags == NO
			|| (*flags)->flags == '0'))
		ft_printf_write(' ', flags, ((*flags)->width - digit_nb2));
	if ((*flags)->pr_nb > digit_nb)
		ft_printf_write('0', flags, ((*flags)->pr_nb - digit_nb));
	return (digit_nb2);
}

int		adrs_conv_prcss(t_list **flags, size_t digit_nb, size_t digit_nb2)
{
	if ((*flags)->pr_nb > digit_nb)
		digit_nb2 = (*flags)->pr_nb;
	if ((*flags)->width > digit_nb2 && ((*flags)->flags == NO
			|| (*flags)->flags == '0'))
		ft_printf_write(' ', flags, ((*flags)->width - digit_nb2));
	if ((*flags)->pr_nb > digit_nb)
		ft_printf_write('0', flags, ((*flags)->pr_nb - digit_nb));
	return (digit_nb2);
}

void	type_selection(int x, char *s, t_list *flags)
{
	if (flags->type == 'c')
		char_conversion(x, flags);
	else if (flags->type == 's')
		str_conversion(s, flags);
	else if (flags->type == 'd' || flags->type == 'i')
		int_conversion(x, flags);
}

void	type_selection2(unsigned int y, void *z, t_list *flags)
{
	if (flags->type == 'p')
		adrs_conversion(z, flags);
	//else if (flags->type == 'u')
		//unsigned_conversion(x, flags);*/
	else if (flags->type == 'x')
		hexa_conversion(y, flags);
	else if (flags->type == 'X')
		HEXA_conversion(y, flags);
	else if (flags->type == 'p')
		z = 0;
}
