/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/31 13:37:52 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:13:01 by alganoun    ###    #+. /#+    ###.fr     */
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

	a = 340;
	//t_printf("coucou est ce que %-367.987d");
	printf("1 : this is the number i want : %05.d\n", a);
	return (0);
}
