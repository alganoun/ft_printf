/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mainpaul2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 14:49:33 by pbesson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:13:24 by jobenass    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./ft_printf.h"
# include <limits.h>

int		ft_printf(const char *fmt, ...);

int		ft_check_return(int mine, int real, int count)
{
	//printf("\n\nreturn value : \nmine : %d\nreal : %d\n", mine, real);
	if (mine == real)
		printf("\n\n\033[0;32m           Correct !\033[00m");
	else
	{
		count++;
		printf("\n\n\033[0;31m            Wrong !\033[00m");
	}
	return (count);
}

int		main(void)
{
	int count;
	int mine;
	int real;

	count = 0;
	mine = 0;
	real = 0;

	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS AVEC |c| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c|, 'c'\033[00m\n\n");
	mine = ft_printf("%c", 'c');
	real = printf("%c", 'c');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c|, 'c'\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%c|", 'c');
	real = printf("\n   printf : |%c|", 'c');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c| et |%%c|, 'c', 1\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%c| et |%c|", 'c', 1);
	real = printf("\n   printf : |%c| et |%c|", 'c', 1);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c%%c|, 'c', 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%c%c|", 'c', 'c');
	real = printf("\n   printf : |%c%c|", 'c', 'c');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%s%%s|, test, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%s%s|", "test", "test");
	real = printf("\n   printf : |%s%s|", "test", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS AVEC |s| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%s|, PkTVgLY7Ls0pp2Da1ZbvoOkNWjopQm2j9IEbDzpLrW4cBkFMPFvb19\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%s|", "PkTVgLY7Ls0pp2Da1ZbvoOkNWjopQm2j9IEbDzpLrW4cBkFMPFvb19");
	real = printf("\n   printf : |%s|", "PkTVgLY7Ls0pp2Da1ZbvoOkNWjopQm2j9IEbDzpLrW4cBkFMPFvb19");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%s|, afiojfjadsifjaiosjf\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%s|", "afiojfjadsifjaiosjf");
	real = printf("\n   printf : |%s|", "afiojfjadsifjaiosjf");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%s|, yoVDXsxV9SBX7hQUcVK6\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%s|", "yoVDXsxV9SBX7hQUcVK6");
	real = printf("\n   printf : |%s|", "yoVDXsxV9SBX7hQUcVK6");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |*| AVEC |s| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%s| et |%%s|, bonjour, bienvenue\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%s| et |%s|", "bonjour", "bienvenue");
	real = printf("\n   printf : |%s| et |%s|", "bonjour", "bienvenue");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*s|, 6, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*s|", 6, "test");
	real = printf("\n   printf : |%*s|", 6, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*s|, 6, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*s|", 6, "test");
	real = printf("\n   printf : |%-*s|", 6, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%---*s|, 6, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%---*s|", 6, "test");
	real = printf("\n   printf : |%---*s|", 6, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%---*s|, 0, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%---*s|", 0, "test");
	real = printf("\n   printf : |%---*s|", 0, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%---*s| et |%%*s|, 10, test, 15, 2 eme var\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%---*s| et |%*s|", 10, "test", 15, "2 eme var");
	real = printf("\n   printf : |%---*s| et |%*s|", 10, "test", 15, "2 eme var");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*s|, 15, NULL\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*s|", 15, NULL);
	real = printf("\n   printf : |%*s|", 15, NULL);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.*s|, 10, 3, NULL\033[00m\n\n");
	mine = ft_printf("\n   ft_printf : |%*.*s|", 10, 3, NULL);
	real = printf( "\n      printf : |%*.*s|", 10, 3, NULL);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");


	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m\033[0;33m/!\\TESTS SUR |*| avec |c| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%---*c|, 6, 'd'\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%---*c|", 6, 'd');
	real = printf("\n   printf : |%---*c|", 6, 'd');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*c|, -123, 'd'\033[00m\n\n");
	ft_printf("ft_printf : |%*c|", -123, 'd');
	printf("\n   printf : |%*c|", -123, 'd');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");


	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |*| avec |d| :\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%---*d|, 10, 12345\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%---*d|", 10, 12345);
	real = printf("\n   printf : |%---*d|", 10, 12345);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*d|, -9, -87\033[00m\n\n");
	ft_printf("\nft_printf : |%*d|", -9, -87);
	printf("\n   printf : |%*d|", -9, -87);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%02d|, -1\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%02d|", -1);
	real = printf("\n   printf : |%02d|", -1);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%07d|, -123456\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%07d|", -123456);
	real = printf("\n   printf : |%07d|", -123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |*| avec |u| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*u|, 20, 1234\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*u|", 20, 1234);
	real = printf("\n   printf : |%-*u|", 20, 1234);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*u|, 20, -9\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*u|", 20, -9);
	real = printf("\n   printf : |%*u|", 20, -9);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.0u|, -15\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.0u|", -15);
	real = printf("\n   printf : |%10.0u|", -15);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%u|, 87\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%u|", 87);
	real = printf("\n   printf : |%u|", 87);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |*| avec |x| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*x|, 20, 1234\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*x|", 20, 1234);
	real = printf("\n   printf : |%*x|", 20, 1234);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*X|, 10, 99999\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*X|", 10, 99999);
	real = printf("\n   printf : |%-*X|", 10, 99999);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%x|, -2802222\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%x|", -2802222);
	real = printf("\n   printf : |%x|", -2802222);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%x|, -12\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%x|", -12);
	real = printf("\n   printf : |%x|", -12);
	count = ft_check_return(mine, real, count);

	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%012x|, -12\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%012x|", -12);
	real = printf("\n   printf : |%012x|", -12);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%020.2x|", INT_MIN);
	real = printf("\n   printf : |%020.2x|", INT_MIN);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0x|, -12345\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0x|", -12345);
	real = printf("\n   printf : |%0.0x|", -12345);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0x|", 0);
	real = printf("\n   printf : |%0.0x|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.10x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.10x|", 0);
	real = printf("\n   printf : |%0.10x|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.10x|, 10\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.10x|", 10);
	real = printf("\n   printf : |%0.10x|", 10);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.0x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.0x|", 0);
	real = printf("\n   printf : |%10.0x|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%x|", 0);
	real = printf("\n   printf : |%x|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%54.0x|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%54.0x|", -123456);
	real = printf("\n   printf : |%54.0x|", -123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
		printf("\033[0;34m     test : |%%*X|, -9, -87\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*X|", -9, -87);
	real = printf("\n   printf : |%*X|", -9, -87);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*X|, 6, -15\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*X|", 6, -15);
	real = printf("\n   printf : |%-*X|", 6, -15);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*X|, 6, 10\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*X|", 6, 10);
	real = printf("\n   printf : |%-*X|", 6, 10);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |.| AVEC |s| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.d|, 55\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.d|", 55);
	real = printf("\n   printf : |%.d|", 55);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%20.s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%20.s|", "test");
	real = printf("\n   printf : |%20.s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%2.s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%2.s|", "test");
	real = printf("\n   printf : |%2.s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.0s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.0s|", "test");
	real = printf("\n   printf : |%.0s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%2.0s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%2.0s|", "test");
	real = printf("\n   printf : |%2.0s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10s|", "test");
	real = printf("\n   printf : |%10s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%2s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%2s|", "test");
	real = printf("\n   printf : |%2s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.22s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.22s|", "test");
	real = printf("\n   printf : |%.22s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.2s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.2s|", "test");
	real = printf("\n   printf : |%.2s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.10s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.10s|", "test");
	real = printf("\n   printf : |%10.10s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.2s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.2s|", "test");
	real = printf("\n   printf : |%10.2s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.*s|, 2, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.*s|", 2, "test");
	real = printf("\n   printf : |%.*s|", 2, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-20s|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-20s|", "test");
	real = printf("\n   printf : |%-20s|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-*.*s|, -3, -3, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*.*s|", -3, -3, "test");
	real = printf("\n   printf : |%-*.*s|", -3, -3, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.*s|, 10, -10, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.*s|", 10, -10, "test");
	real = printf("\n   printf : |%*.*s|", 10, -10, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.*s|, 10, 10, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.*s|", 10, 10, "test");
	real = printf("\n   printf : |%*.*s|", 10, 10, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.015s|, bonjour\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.015s|", "bonjour");
	real = printf("\n   printf : |%.015s|", "bonjour");
	count = ft_check_return(mine, real, count);



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |.| AVEC |d| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.d|", 0);
	real = printf("\n   printf : |%.d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*d|, -9, -87\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*d|", -9, -87);
	real = printf("\n   printf : |%*d|", -9, -87);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%54.0d|, 47788\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%54.0d|", 47788);
	real = printf("\n   printf : |%54.0d|", 47788);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%010.0d|, 47788\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%010.0d|", 47788);
	real = printf("\n   printf : |%010.0d|", 47788);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%010.0d|, -47788\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%010.0d|", -47788);
	real = printf("\n   printf : |%010.0d|", -47788);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.10d|, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.10d|", 123);
	real = printf("\n   printf : |%0.10d|", 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%020.0d|, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%020.0d|", 123);
	real = printf("\n   printf : |%020.0d|", 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%010.20d|, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%010.20d|", 123);
	real = printf("\n   printf : |%010.20d|", 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.54d|, -123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.54d|", -123);
	real = printf("\n   printf : |%0.54d|", -123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.10d|, -123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.10d|", -123);
	real = printf("\n   printf : |%10.10d|", -123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.10d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.10d|", 0);
	real = printf("\n   printf : |%10.10d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%3.7d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%3.7d|", 0);
	real = printf("\n   printf : |%3.7d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%3.7d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%3.7d|", 0);
	real = printf("\n   printf : |%3.7d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, -45, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", -45, 123);
	real = printf("\n   printf : |%0.*d|", -45, 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%20.10d|, -123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%20.10d|", -123);
	real = printf("\n   printf : |%20.10d|", -123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.*d|, -20, 20, -123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.*d|", -20, 20, -123);
	real = printf("\n   printf : |%*.*d|", -20, 20, -123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, -45, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", -45, 0);
	real = printf("\n   printf : |%0.*d|", -45, 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0d|", 0);
	real = printf("\n   printf : |%0.0d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.0d|, -45, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.0d|", -45, 0);
	real = printf("\n   printf : |%*.0d|", -45, 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, 10, INT_MIN\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", 10, INT_MIN);
	real = printf("\n   printf : |%0.*d|", 10, INT_MIN);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, -45, INT_MIN\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", -45, INT_MIN);
	real = printf("\n   printf : |%0.*d|", -45, INT_MIN);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, 10, -970347236\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", 10, -970347236);
	real = printf("\n   printf : |%0.*d|", 10, -970347236);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, 9, -97034723\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", 9, -97034723);
	real = printf("\n   printf : |%0.*d|", 9, -97034723);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*d|, 10, -511016700\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*d|", 10, -511016700);
	real = printf("\n   printf : |%0.*d|", 10, -511016700);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%012%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%012%|");
	real = printf("\n   printf : |%012%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%012d|, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%012d|", 123);
	real = printf("\n   printf : |%012d|", 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0*d|, 012, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0*d|", 012, 123);
	real = printf("\n   printf : |%0*d|", 012, 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%046d|, INT_MIN\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%046d|", INT_MIN);
	real = printf("\n   printf : |%046d|", INT_MIN);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%010d|, -123456\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%010d|", -123456);
	real = printf("\n   printf : |%010d|", -123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.10d|, -123456\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.10d|", -123456);
	real = printf("\n   printf : |%0.10d|", -123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%046d|, -123456\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%46d|", -123456);
	real = printf("\n   printf : |%46d|", -123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.35d|, -44870\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.35d|", -44870);
	real = printf("\n   printf : |%0.35d|", -44870);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%50.55d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.55d|", 0);
	real = printf("\n   printf : |%0.55d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.55d|, -123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.55d|", -123);
	real = printf("\n   printf : |%0.55d|", -123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%4.3i|, -1\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%4.3i|", -1);
	real = printf("\n   printf : |%4.3i|", -1);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%01i|, -1\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%01i|", -1);
	real = printf("\n   printf : |%01i|", -1);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.2i|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.2i|", 0);
	real = printf("\n   printf : |%10.2i|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-2.1i|, -1\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-2.1i|", -1);
	real = printf("\n   printf : |%-2.1i|", -1);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0*d|, -10, 42\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0*d|", -10, 42);
	real = printf("\n   printf : |%0*d|", -10, 42);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%d-*.5d%%d|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-*.5d|", -15, 1234);
    real = printf("\n   printf : |%-*.5d|", -15, 1234);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%4.0d|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%4.0d|", 0);
	real = printf("\n   printf : |%4.0d|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |.| AVEC |c| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-10c|, \\0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-10c|", '\0');
	real = printf("\n   printf : |%-10c|", '\0');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c|, \\0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%c|", '\0');
	real = printf("\n   printf : |%c|", '\0');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%c|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%c|", 0);
	real = printf("\n   printf : |%c|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");


	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |%%| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%54%%s|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%54%s|");
	real = printf("\n   printf : |%54%s|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%054%%s|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%054%s|");
	real = printf("\n   printf : |%054%s|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*%%|, 10\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*%|", 10);
	real = printf("\n   printf : |%0.*%|", 10);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	
	

	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |.| AVEC |u| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.54u|, 123456\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.54u|", 123456);
	real = printf("\n   printf : |%0.54u|", 123456);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.0u|, 10, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.0u|", 10, 0);
	real = printf("\n   printf : |%*.0u|", 10, 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0u|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0u|", 0);
	real = printf("\n   printf : |%0.0u|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.0u|, 123\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0u|", 123);
	real = printf("\n   printf : |%0.0u|", 123);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.0u|, -45, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.0u|", -45, 0);
	real = printf("\n   printf : |%*.0u|", -45, 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.u|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.u|", 0);
	real = printf("\n   printf : |%10.u|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.10u|, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.10u|", 0);
	real = printf("\n   printf : |%10.10u|", 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%*.*u|, -45, -45, 0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%*.*u|", -45, -45, 0);
	real = printf("\n   printf : |%*.*u|", -45, -45, 0);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.u|, -15\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.u|", -15);
	real = printf("\n   printf : |%10.u|", -15);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |p| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.p|, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.p|", "test");
	real = printf("\n   printf : |%.p|", "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%p|, \\0\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%p|", "\0");
	real = printf("\n   printf : |%p|", "\0");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%.p| et |%%p|, NULL, test\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%.p| et |%p|", NULL, "test");
	real = printf("\n   printf : |%.p| et |%p|", NULL, "test");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%p|, NULL\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%p|", NULL);
	real = printf("\n   printf : |%p|", NULL);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%6p|, NULL\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%6p|", NULL);
	real = printf("\n   printf : |%6p|", NULL);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |all| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\033[0;34m     test : |%%s %%d %%p %%x %%X %%i %%u %%c|, 87\033[00m\n\n");
	mine = ft_printf("printf    :\t|%s %d %p %x %X %i %u %c|\n", "test", 123, "test", 123, -123, 123, 123, 'c');
	real = printf("ft_printf :\t|%s %d %p %x %X %i %u %c|\n", "test", 123, "test", 123, -123, 123, 123, 'c');
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");


	printf("\033[0;33m\n\n\n/*-------------------------------------*/\033[00m\n");
	printf("\033[0;33m/!\\TESTS SUR |%%| :\033[00m\n");
	printf("\033[0;33m/*-------------------------------------*/\033[00m\n\n");
	printf("\033[0;34m     test : |%%0.0%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.0%|");
	real = printf("\n   printf : |%0.0%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.0%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.0%|");
	real = printf("\n   printf : |%10.0%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.10%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.10%|");
	real = printf("\n   printf : |%0.10%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%10.0%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%10.0%|");
	real = printf("\n   printf : |%10.0%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%-10.0%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%-10.0%|");
	real = printf("\n   printf : |%-10.0%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0.*%%|, -10\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0.*%|", -10);
	real = printf("\n   printf : |%0.*%|", -10);
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%0000000-000002%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%0000000-000002%|");
    real = printf("\n   printf : |%0000000-000002%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%000002%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%000002%|");
    real = printf("\n   printf : |%000002%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%--0--0--00-00-04.10%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%--0--0--00-00-04.10%|");
    real = printf("\n   printf : |%--0--0--00-00-04.10%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%020.2%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%020.2%|");
    real = printf("\n   printf : |%020.2%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%020.10%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%020.10%|");
    real = printf("\n   printf : |%020.10%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");
	printf("\033[0;34m     test : |%%2.10%%|\033[00m\n\n");
	mine = ft_printf("\nft_printf : |%2.10%|");
    real = printf("\n   printf : |%2.10%|");
	count = ft_check_return(mine, real, count);
	printf("\n\n\\*/--------------------------------\\*\n\n");



	if (count > 0)
		printf("\n\n\n\033[0;31m      %d reponse.s fausse.s\n\n\033[00m", count);
	else
		printf("\n\n\n\033[0;32m         all good\033\n\n[00m");
	

	// mine = ft_printf("\nft_printf : |%-*.*s|", -10, -10, "test");
	// real = printf("\n   printf : |%*.*s|", 10, 3, "test");
	// count = ft_check_return(mine, real, count);
	// printf("\n\n\\*/--------------------------------\\*\n\n");

	// mine = ft_printf("\nft_printf : |%-*.s|", 10, "test");
	// real = printf("\n   printf : |%-*.s|", 10, "test");
	
	// mine = ft_printf("\nft_printf : |%*s|", 6, "test");
	// real = printf("\n   printf : |%*s|", 6, "test");
	// real = ft_printf("\n   ft_printf : |%20.20s|", "test");
	// real = ft_printf("\n   ft_printf : |%.20s|", "test");
	// real = ft_printf("\n   ft_printf : |%s|", "test");

	// mine = ft_printf("\nft_printf : |%-10c|", 0);
	// real = printf("\n   printf : |%-10c|", 0);


	// mine = ft_printf("\n\n\n\n\nft_printf : |%-10d|", -87);
	// real = printf("\n   printf : |%10d|", -87);
	// real = printf("\n   printf : |%-10d|", -87);
	// real = printf("\n   printf : |%*d|", -10, -87);

	// real = printf("\n   printf : |%10.10d|", 0);
	// real = printf("\n   printf : |%10.0d|", 0);
	// real = printf("\n   printf : |%10.0d|", 123);
	// real = printf("\n   printf : |%10.d|", 123);
	// real = printf("\n   printf : |%10.d|", 0);

	// real = ft_printf("\n   ft_printf : |%*.*s|", 10, 0, "test");
	// real = printf("\n      printf : |%*.*s|", 10, 0, "test");

	return (0);
}
