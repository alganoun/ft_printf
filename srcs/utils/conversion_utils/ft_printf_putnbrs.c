/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_putnbrs.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 12:14:56 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 15:13:28 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/libft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(int nb, t_list *flags, char *base)
{
	int		nb_base;
	int		result;
	long	n;

	n = nb;
	nb_base = ft_strlen(base);
	if (n < 0)
	{
		if (flags->neg == NO)
			ft_printf_write('-', &flags, 1);
		result = -(n % nb_base);
		n = -(n / nb_base);
	}
	else
	{
		result = n % nb_base;
		n = n / nb_base;
	}
	if (n != 0)
		ft_putnbr_base(n, flags, base);
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

void	ft_unsigned_putnbr_base(unsigned int nb, t_list *flags, char *base)
{
	unsigned int nb_base;
	unsigned int result;

	nb_base = ft_strlen(base);
	result = nb % nb_base;
	nb = nb / nb_base;
	if (nb != 0)
		ft_unsigned_putnbr_base(nb, flags, base);
	ft_printf_write(base[result], &flags, 1);
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
	ft_printf_write(base[result], flags, 1);
}

