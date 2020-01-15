/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft_printf.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 15:09:20 by alganoun     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:39:45 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define YES 1
# define NO 0

typedef struct		s_list
{
	int				ret;
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precs;
	unsigned int	pr_nb;
	unsigned int 	type;
	unsigned int	neg;
	unsigned int	temp;
}					t_list;

int		ft_printf(const char *str, ...)
 __attribute__((format(printf,1,2)));

int		check_charset(char c);
int		ft_parsing(char *str, t_list **flags);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_strlen(char *str);
int		ft_digit_nb(int nb);
int		ft_digit_hex_nb(int nb, t_list **flags, char *base);
int		int_conv_prcss(int x, t_list **flags, size_t digit_nb, size_t digit_nb2);
int		hex_conv_prcss(t_list **flags, size_t digit_nb, size_t digit_nb2);
void	char_conversion(int x, t_list *flags);
void	str_conversion(char *str, t_list *flags);
void	int_conversion(int x, t_list *flags);
void	hexa_conversion(int x, t_list *flags);
void	ft_printf_write(int c, t_list **flags, int nb);
void	type_selection(int x, char *s, t_list *flags);
void	ft_putstr(char *str, t_list *flags, int nb);
void	ft_putnbr_base(int nb, t_list *flags, char *base);

#endif
