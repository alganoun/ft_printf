/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:58:45 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:56:30 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

void	ft_printf_write(int c, t_list **flags, int nb)
{
	while (nb > 0)
	{
		write(1, &c, 1);
		(*flags)->ret++;
		nb--;
	}
}

int		ft_initiate(t_list **flags)
{
	if (!(*flags = malloc(sizeof(t_list))))
		return (-1);
	if (*flags)
	{
		(*flags)->flags = 0;
		(*flags)->width = 1;
		(*flags)->precs = 0;
		(*flags)->pr_nb = 0;
		(*flags)->type = 0;
		(*flags)->ret = 0;
	}
	return (0);
}

void	ft_conversion(va_list lst, t_list *flags)
{
	int		x;
	char	*s;

	x = 0;
	s = NULL;
	if (flags->type == 's')
		s = va_arg(lst, char *);
	else
		x = va_arg(lst, int);
	type_selection(x, s, flags);
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
			ft_conversion(lst, flags);
		}
		else
			ft_printf_write(s[i], &flags, 1);
		i++;
	}
	write(1, "\n", 1);
	printf("flags = * %c *\n", flags->flags);
	printf("width = * %d *\n", flags->width);
	printf("precision = * %d *\n", flags->precs);
	printf("precision number = * %d *\n", flags->pr_nb);
	printf("conversion type = * %c *\n", flags->type);
	printf("return = * %d *", flags->ret);
	if (flags)
		free(flags);
	return (flags->ret);
}
