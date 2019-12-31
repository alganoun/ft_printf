/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 12:48:55 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 17:49:59 by alganoun    ###    #+. /#+    ###.fr     */
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
		if ((c != charset[i]) && ((c <= 65 && c >= 90) || (c <= 97 && c >= 122)))
			return (-1);
		if(charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_parsing(char *str, t_list **flags)
{
	int i;

	i = 0;
	while (str[i] && check_charset(str[i]) != 1)
	{
		if (check_charset(str[i]) == -1)
			return (-1);
		if (*flags)
		{
			if (str[i] == '-' && str[i - 1] != '-')
				(*flags)->flags = 1;
			else if (str[i] >= '0' && str[i] <= '9')
			{
				(*flags)->width = str[i] - 48; // revoir le parsing avec atoi et ft_digit.
				if (str[i - 1] == '')
			}
			else if (str[i] == '.')
				(*flags)->precs = 1;
			else if (check_charset(str[i + 1] == 1))
				(*flags)->type = str[i + 1];
		}
		i++;
	}
	return (i);
}
