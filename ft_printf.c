/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:58:45 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 16:51:45 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

void	ft_printf_write(char c, t_list **flags)
{
	write(1, &c, 1);
	(*flags)->ret++;
}

int		ft_initiate(t_list **flags)
{
	if(!(*flags = malloc(sizeof(t_list))))
		return (-1);
	if (*flags)
	{
		(*flags)->flags = 0;
		(*flags)->width = 0;
		(*flags)->precs = 0;
		(*flags)->type= 0;
		(*flags)->ret = 0;
	}
	return (0);
}

void ft_conversion(va_list lst, t_list *flags)
{
	int		x;
	char	*s;

	x = 0;
	s = NULL;
	if (flags->type == s)
		s = va_arg(lst, char *);
	else
		x = va_arg(lst, int);
	ft_type_selection(x, s, flags);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	char	*s;
	t_list	*flags;
	va_list lst;

	i = 0;
	s = (char *)str;
	va_start(lst, str);
	if (ft_initiate(&flags) == -1)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i = i + ft_parsing(&s[i + 1], &flags) + 1;

			//ft_conversion()
		}
		else
			ft_printf_write(s[i], &flags);
		i++;
	}
	return (flags->ret);
}

/*	write(1, "\n", 1);
	printf("flags = * %c *\n", flags->flags);
	printf("width = * %d *\n", flags->width);
	printf("precision = * %d *\n", flags->precs);
	printf("conversion type = * %c *\n", flags->type);
	printf("return = * %d *", flags->ret);
