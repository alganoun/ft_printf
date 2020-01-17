/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion_utils3.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 16:51:04 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:28:11 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_adrs_digit_nb(unsigned long nb, t_list **flags, char *base)
{
	unsigned long nb_base;
	unsigned long result;

	nb_base = ft_strlen(base);
	result = nb % nb_base;
	nb = nb / nb_base;
	if (nb != 0)
		ft_adrs_digit_nb(nb, flags, base);
	(*flags)->temp++;
	return ((*flags)->temp + 2);
}

void	ft_putnbr_adrs_base(unsigned long nb, t_list **flags, char *base)
{
	unsigned long	nb_base;
	unsigned long	result;

	nb_base = ft_strlen(base);
	result = nb % nb_base;
	nb = nb / nb_base;
	if (nb != 0)
		ft_putnbr_adrs_base(nb, flags, base);
	if ((*flags)->precs != 1)
		ft_printf_write(base[result], flags, 1);
}
