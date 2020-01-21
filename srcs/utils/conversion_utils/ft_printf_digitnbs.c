/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_digitnbs.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 16:51:04 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:25:14 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/libft_printf.h"

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

int		ft_unsigned_digit_nb(unsigned int nb)
{
	unsigned int digit_nb;

	digit_nb = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		digit_nb++;
	}
	return (digit_nb);
}

int		ft_digit_nb(int nb)
{
	int digit_nb;

	digit_nb = 0;
	if (nb < 0)
	{
		nb = -nb;
		digit_nb++;
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

int		ft_digit_hex_nb(unsigned int nb, t_list **flags, char *base)
{
	unsigned int nb_base;
	unsigned int result;

	nb_base = ft_strlen(base);
	result = nb % nb_base;
	nb = nb / nb_base;
	if (nb != 0)
		ft_digit_hex_nb(nb, flags, base);
	(*flags)->temp++;
	return ((*flags)->temp);
}
