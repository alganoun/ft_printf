/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:58:45 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 17:21:31 by alganoun    ###    #+. /#+    ###.fr     */
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

int		ft_printf(const char *str, ...)
{
	int		i;
	char	*s;
	t_list	*flags;

	i = 0;
	s = (char *)str;
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
	write(1, "\n", 1);
	printf("%d\n", flags->flags);
	printf("%d\n", flags->width);
	printf("%d\n", flags->precs);
	printf("%d\n", flags->type);
	printf("%d", flags->ret);
	return (flags->ret);
}
