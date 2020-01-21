/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_processes.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 16:36:13 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:03:53 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/libft_printf.h"

int	int_conv_prcss(int x, t_list **flags, int digit_nb, int digit_nb2)
{
	if ((*flags)->pr_nb > digit_nb)
	{	
		digit_nb2 = (*flags)->pr_nb;
		if (x < 0)
			digit_nb2 = digit_nb2 + 1;
	}
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

int		hex_conv_prcss(t_list **flags, int digit_nb, int digit_nb2)
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

int		adrs_conv_prcss(t_list **flags, int digit_nb, int digit_nb2)
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
