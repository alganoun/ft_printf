/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 12:48:55 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:26:09 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft_printf.h"

int		check_charset(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "csdpuixX%";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}



void		ft_parsing_atoi(char *str, int i, t_list **flags, va_list lst)
{
	if (str[i - 1] != '.' && str[i] == '*')
	{
		(*flags)->width = va_arg(lst, unsigned int);
		if ((*flags)->width < 0)
		{
			(*flags)->flags = '-';
			(*flags)->width = -((*flags)->width);
		}
	}
	else if (str[i - 1] != '.')
		(*flags)->width = ft_atoi(&str[i]);
	if (str[i - 1] == '.' && str[i] == '*')
	{
		(*flags)->pr_nb = va_arg(lst, unsigned int);
		if ((*flags)->pr_nb < 0)
			(*flags)->precs = 0;
	}
	else if (str[i - 1] == '.')
		(*flags)->pr_nb = ft_atoi(&str[i]);
}

int		ft_parsing(char *str, t_list **flags, va_list lst)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || (i == 0 && str[i] == '0'))
			(*flags)->flags = str[i];
		else if (ft_isdigit(str[i]) == 1 &&
			(ft_isdigit(str[i - 1]) == 0 || i == 0 || str[i - 1] == '0'))
			ft_parsing_atoi(str, i, flags, lst);
		else if (str[i] == '.')
			(*flags)->precs = YES;
		if (check_charset(str[i]) == 1)
		{
			(*flags)->type = str[i];
			return (i);
		}
		i++;
	}
	return (0);
}
