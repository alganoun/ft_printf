/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft_printf.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 15:09:20 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 17:50:00 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				ret;
	int				flags;
	int				width;
	int				precs;
	int 			type;
}					t_list;

int		check_charset(char c);
int		ft_parsing(char *str, t_list **flags);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
