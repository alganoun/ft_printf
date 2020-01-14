/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 12:14:56 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 18:14:54 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_digit_nb(int nb)
{
	int digit_nb;

	digit_nb = 0;
	if (nb < 0)
	{
		digit_nb++;
		nb = -nb;
	}
	else if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		digit_nb++;
	}
	return (digit_nb);
}

void	ft_putnbr_base(int nb, t_list *flags, char *base)
{
	int nb_base;
	int result;

	nb_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_printf_write('-', &flags, 1);
		result = -(nb % nb_base);
		nb = nb / nb_base;
	}
	else
	{
		result = nb % nb_base;
		nb = nb / nb_base;
	}
	if (nb != 0)
		ft_putnbr_base(nb, flags, base);
	ft_printf_write(base[result], &flags, 1);
}