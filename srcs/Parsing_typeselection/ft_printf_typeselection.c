/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_typeselection.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 12:14:40 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:21:40 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft_printf.h"

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
	else if (flags->type == 'u')
		unsigned_conversion(y, flags);
	else if (flags->type == 'x')
		hexa_conversion(y, flags);
	else if (flags->type == 'X')
		HEXA_conversion(y, flags);
	else if (flags->type == '%')
		pourcent_conversion(flags);
}
