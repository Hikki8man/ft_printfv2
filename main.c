#include <stdio.h>
#include "include/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>

int main(void) {
	int z = 1;
/*
	ft_printf("%0*.*d\n", 21, 10, -101);
	printf("%0*.*d\n", 21, 10, -101);
	printf("Test %d\n", i++);
	ft_printf(" %d \n", 0);
	printf(" %d \n", 0);
	printf("Test %d\n", i++);
	ft_printf(" %.d \n", 0);
	printf(" %.d \n", 0);
	printf("Test %d\n", i++);
	ft_printf(" %-.2d \n", 0);
	printf(" %-.2d \n", 0);
	printf("Test %d\n", i++);
	ft_printf(" %-2.2d \n", 0);
	printf(" %-2.2d \n", 0);
	printf("Test %d\n", i++);
	ft_printf(" %-3.2d \n", 0);
	printf(" %-3.2d \n", 0);
	printf("Test %d\n", i++);
	ft_printf(" %-3.2d %10.42d \n", 0, 0);
	printf(" %-3.2d %10.42d \n", 0, 0);
	printf("Test %d\n", i++);
	ft_printf(" %-3.2d %10.42d \n", 1, -1);
	printf(" %-3.2d %10.42d \n", 1, -1);
	printf("Test %d\n", i++);
	ft_printf(" %-3.2d %10.42d \n", 10, -10);
	printf(" %-3.2d %10.42d \n", 10, -10);
	printf("Test %d\n", i++);
	ft_printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	printf("Test %d\n", i++);
	ft_printf(" *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	printf(" *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	printf("Test %d\n", i++);
	ft_printf(" *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	printf(" *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	printf("Test %d\n", i++);
	ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	printf("Test %d\n", i++);
	ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	printf("Test %d\n", i++);
	ft_printf(" 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	printf("Test %d\n", i++);
	ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	printf("Test %d\n", i++);
	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	printf("Test %d\n", i++);
	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	printf("Test %d\n", i++);
	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	printf("Test %d\n", i++);
	ft_printf(" --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("Test %d\n", i++);
	ft_printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("Test %d\n", i++);
	ft_printf(" --0*%-0*.3d*0 0*%-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.3d*0 0*%-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("Test %d\n", i++);
	ft_printf(" --0*%-0*.4d*0 0*%-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.4d*0 0*%-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("Test %d\n", i++);
	ft_printf("%-20.5de\n", -1243);
	printf("%-20.5de\n", -1234);
		printf("Test %d\n", i++);
	ft_printf("%9.2d\n", UINT_MAX);
	printf("%9.2d\n", UINT_MAX);

	printf("Test %d\n", i++);
	ft_printf("%9.10d\n", UINT_MAX);
	printf("%9.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%10.0d\n", UINT_MAX);
	printf("%10.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%10.1d\n", UINT_MAX);
	printf("%10.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%10.2d\n", UINT_MAX);
	printf("%10.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%10.10d\n", UINT_MAX);
	printf("%10.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%11.0d\n", UINT_MAX);
	printf("%11.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%11.1d\n", UINT_MAX);
	printf("%11.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%11.2d\n", UINT_MAX);
	printf("%11.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%11.10d\n", UINT_MAX);
	printf("%11.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-9.0d\n", UINT_MAX);
	printf("%-9.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-9.1d\n", UINT_MAX);
	printf("%-9.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-9.2d\n", UINT_MAX);
	printf("%-9.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-9.10d\n", UINT_MAX);
	printf("%-9.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-10.0d\n", UINT_MAX);
	printf("%-10.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-10.1d\n", UINT_MAX);
	printf("%-10.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-10.2d\n", UINT_MAX);
	printf("%-10.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-10.10d\n", UINT_MAX);
	printf("%-10.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-11.0d\n", UINT_MAX);
	printf("%-11.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-11.1d\n", UINT_MAX);
	printf("%-11.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-11.2d\n", UINT_MAX);
	printf("%-11.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%-11.10d\n", UINT_MAX);
	printf("%-11.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%09.0d\n", UINT_MAX);
	printf("%09.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%09.1d\n", UINT_MAX);
	printf("%09.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%09.2d\n", UINT_MAX);
	printf("%09.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%09.10d\n", UINT_MAX);
	printf("%09.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%010.0d\n", UINT_MAX);
	printf("%010.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%010.1d\n", UINT_MAX);
	printf("%010.1d\n", UINT_MAX);
	 printf("Test %d\n", i++);
	ft_printf("%010.2d\n", UINT_MAX);
	printf("%010.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%010.10d\n", UINT_MAX);
	printf("%010.10d\n", UINT_MAX) ;
	printf("Test %d\n", i++);
	ft_printf("%011.0d\n", UINT_MAX);
	printf("%011.0d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%011.1d\n", UINT_MAX);
	printf("%011.1d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%011.2d\n", UINT_MAX);
	printf("%011.2d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%011.10d\n", UINT_MAX);
	printf("%011.10d\n", UINT_MAX);
	printf("Test %d\n", i++);
	ft_printf("%09.0d\n", UINT_MAX + 1);
	printf("%09.0d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%09.1d\n", UINT_MAX + 1);
	printf("%09.1d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%09.2d\n", UINT_MAX + 1);
	printf("%09.2d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%09.10d\n", UINT_MAX + 1);
	printf("%09.10d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%010.0d\n", UINT_MAX + 1);
	printf("%010.0d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%010.1d\n", UINT_MAX + 1);
	printf("%010.1d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%010.2d\n", UINT_MAX + 1);
	printf("%010.2d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%010.10d\n", UINT_MAX + 1);
	printf("%010.10d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%011.0d\n", UINT_MAX + 1);
	printf("%011.0d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%011.1d\n", UINT_MAX + 1);
	printf("%011.1d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%011.2d\n", UINT_MAX + 1);
	printf("%011.2d\n", UINT_MAX + 1);
	printf("Test %d\n", i++);
	ft_printf("%04.2d\n", UINT_MAX + 1);
	printf("%04.2d\n", UINT_MAX + 1);*/

	int		a = -2;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%%%dBonjour%", 2));
	printf(" --- Return : %d\n", printf("%%%dBonjour%", 2));


	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%12.20s", "bonjour"));
	printf(" --- Return : %d\n", printf("%12.20s", "bonjour"));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%12.1p", 0));
	printf(" --- Return : %d\n", printf("%12.1p", 0));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%%*.c%c%%*.s*%ps%%*.X", '0', NULL));
	printf(" --- Return : %d\n", printf("%%*.c%c%%*.s*%ps%%*.X", '0', NULL));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.*s", 18, NULL));
	printf(" --- Return : %d\n", printf("%.*s", 18,NULL));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	printf(" --- Return : %d\n", printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%*.*s",-2,1, "abc"));
	printf(" --- Return : %d\n", printf("%*.*s",-2,1, "abc"));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%1s", "bonjour"));
	printf(" --- Return : %d\n", printf("%1s", "bonjour"));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.*u", 2, 8, -42));
	printf(" --- Return : %d\n", printf("%.*u", 2, 8, -42));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%*.*d", 19, 14, -42));
	printf(" --- Return : %d\n", printf("%*.*d", 19, 14, -42));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%6.*d",	2, 1));
	printf(" --- Return : %d\n", printf("%6.*d", 2, 1));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%*.*d", 4, 3, -12));
	printf(" --- Return : %d\n", printf("%*.*d",4, 3, -12));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.*d", 3, -12, 8));
	printf(" --- Return : %d\n", printf("%.*d",3, -12, 8));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%*.1d", -4, 0, 8));
	printf(" --- Return : %d\n", printf("%*.1d",-4, 0, 8));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%*.*d",	-4, 0, -12));
	printf(" --- Return : %d\n", printf("%*.*d",-4, 0, -12));


	ft_printf(" --- Return : %d\n", ft_printf("%12.14p",m));
	printf(" --- Return : %d\n", printf("%12.14p",m));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%12.13p",(void *)0));
	printf(" --- Return : %d\n", printf("%12.13p",(void *)0));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%013.*s",-4, "bonjour"));
	printf(" --- Return : %d\n", printf("%013.*s",-4, "bonjour"));

	//ft_printf(" --- Return : %d\n", ft_printf("%.d", 13));
	//ft_printf(" --- Return : %d\n", printf("%.d", 13));// return to fix ?

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", 2, -2, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf(" --- Return : %d\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", 2, -2, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.d",l));
	printf(" --- Return : %d\n", printf("%.d",l));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.0d",l));
	printf(" --- Return : %d\n", printf("%.0d",l));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.*d", a, l));
	printf(" --- Return : %d\n", printf("%.*d", a, l));

	printf("Test %d\n", z++);
	ft_printf(" --- Return : %d\n", ft_printf("%.*d",-2 , 0));
	printf(" --- Return : %d\n", printf("%.*d",-2 , 0));


	//ft_printf("%0.d\n", i);
	//printf("%0.d\n", i);
	return 0;
}
