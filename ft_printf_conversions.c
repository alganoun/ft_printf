ion/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:51:49 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:51:49 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

void	char_conversion(int x, t_list flags)
{
	if (flags->type == c)
	{
		if (flags->flags == '-')
		{
			// voir pour le traitement des flags
		}
		else if( flags->flags == '0')
		{
			// voir pour le traitement des flags
		}
		else
			ft_rpintf_wirte(x, flags);
	}
}

void	type_selection(int x, char *s, t_list *flags)
{
	if (flags->type == 'c')
		char_conversion(x, flags);
	else if (flags->type == 'd' || flags->type == 'i')
		int_conversion(x, flags);
	else if (flags->type == 'p')
		adrs_conversion(x, flags);
	else if (flags->type == 'u')
		unsigned_conversion(x, flags);
	else if (flags->type == 'x') || (flags->type == 'X')
		hexa_conversion(x, flags);
}

