/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversion_utils2.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 12:14:56 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 17:07:53 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

int		ft_digit_nb(int nb)
{
	int digit_nb;

	digit_nb = 0;
	if (nb < 0)
		nb = -nb;
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

void	ft_putnbr_base(int nb, t_list *flags, char *base)
{
	int nb_base;
	int result;

	nb_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_printf_write('-', &flags, 1);
		result = -(nb % nb_base);
		nb = -(nb / nb_base);
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

void	ft_putnbr_hexa_base(unsigned int nb, t_list *flags, char *base)
{
	unsigned int	nb_base;
	unsigned int	result;

	nb_base = ft_strlen(base);
	result = nb % nb_base;
	nb = nb / nb_base;
	if (nb != 0)
		ft_putnbr_hexa_base(nb, flags, base);
	ft_printf_write(base[result], &flags, 1);
}
