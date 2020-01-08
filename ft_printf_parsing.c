/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 12:48:55 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 14:27:40 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

int		check_charset(char c)
{
	int i;
	char *charset;

	i = 0;
	charset = "csdxX";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_parsing(char *str, t_list **flags)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (*flags)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '0'))
				(*flags)->flags = str[i];
			else if (ft_isdigit(str[i]) == 1 &&
				(ft_isdigit(str[i - 1]) == 0 || i == 0))
			{
				if (i == 1 || i == 0)
					(*flags)->width = ft_atoi(&str[i]);
				if (str[i - 1] == '.')
					(*flags)->precs = ft_atoi(&str[i]);
			}
			else if (str[i] == '.')
				(*flags)->precs = 1;
			if (check_charset(str[i]) == 1)
			{
				(*flags)->type = str[i];
				return (i);
			}
		}
		i++;
	}
	return (0);
}
