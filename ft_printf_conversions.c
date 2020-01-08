/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 16:51:49 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 17:53:49 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

void 	char_conversion(int x, t_list *flags)
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
	if (flags->precs > 0)
		len = flags->precs;
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

void	type_selection(int x, char *s, t_list *flags)
{
	if (flags->type == 'c')
		char_conversion(x, flags);
	 if (flags->type == 's')
	 	str_conversion(s, flags);
	/*else if (flags->type == 'd' || flags->type == 'i')
		int_conversion(x, flags);
	else if (flags->type == 'p')
		adrs_conversion(x, flags);
	else if (flags->type == 'u')
		unsigned_conversion(x, flags);
	else if ((flags->type == 'x') || (flags->type == 'X'))
		hexa_conversion(x, flags);*/
}

