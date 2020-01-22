/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/31 13:37:52 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:14:08 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main()
{
 	//char *s =  "Coucou est ce que ca va";
	//int a;
	//a = 2147483647;
	printf("gh_printf = %020.0u\n", 123);
	ft_printf("ft_printf = %020.0u\n", 123);
	return (0);
}
