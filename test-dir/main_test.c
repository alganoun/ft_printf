/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:35:26 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 15:27:29 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
int ft_calculs(int n1, ...)
{
	int n2;

	va_list(list);
	va_start(list, n1);
	n2 = (int)va_arg(list, int);
	va_end(list);
	return(n1 + n2);
}

int		main()
{
	int res;

	res = ft_calculs(1, 2);
	printf("%d", res);
	return (0);
}
