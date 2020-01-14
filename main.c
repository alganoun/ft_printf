/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/31 13:37:52 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 18:15:13 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main()
{
 	//char *s = "hello";
	int a;

	a = 0;
	printf("1 : this is the number i want : %.7d\n", a);
	ft_printf("2 : this is the number i want : %.7d\n", a);
	return (0);
}
