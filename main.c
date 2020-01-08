/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/31 13:37:52 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:28:31 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main()
{
 char *str = NULL;
	//t_printf("coucou est ce que %-367.987d");
	printf("1 : this is the string i want : %30.5s coucou\n", str);
	ft_printf("2 : this is the string i want : %30.5s coucou\n", str);
	return (0);
}
