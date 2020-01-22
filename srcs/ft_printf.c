/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:58:45 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:21:41 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft_printf.h"
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

void	ft_reset(t_list **flags)
{
	if (*flags)
	{
		(*flags)->flags = NO;
		(*flags)->width = 0;
		(*flags)->precs = NO;
		(*flags)->pr_nb = 0;
		(*flags)->type = 0;
		(*flags)->neg = 0;
		(*flags)->temp = 0;
		(*flags)->temp2 = 0;
	}
}

int		ft_initiate(t_list **flags)
{
	if (!(*flags = malloc(sizeof(t_list))))
		return (-1);
	if (*flags)
	{
		(*flags)->ret = 0;
		ft_reset(flags);
	}
	return (0);
}

void	ft_conversion(va_list lst, t_list *flags)
{
	int				x;
	unsigned int	y;
	void			*z;
	char			*s;

	x = 0;
	y = 0;
	z = 0;
	s = NULL;
	if (flags->type == 's')
		s = va_arg(lst, char *);
	else if (flags->type == 'd' || flags->type == 'i' || flags->type == 'c')
		x = va_arg(lst, int);
	else if (flags->type == 'u' || flags->type == 'x' || flags->type == 'X')
		y = va_arg(lst, unsigned int);
	else if (flags->type == 'p')
		z = va_arg(lst, void *);
	type_selection(x, s, flags);
	type_selection2(y, z, flags);

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
			i = i + ft_parsing(&s[i + 1], &flags, lst) + 1;
			ft_conversion(lst, flags);
		}
		else
			ft_printf_write(s[i], &flags, 1);
		ft_reset(&flags);
		i++;
	}
	if (flags)
		free(flags);
	return (flags->ret);
}
