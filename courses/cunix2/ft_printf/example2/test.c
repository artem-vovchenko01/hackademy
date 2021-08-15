#include <stdio.h>

#include "libft.h"

int main()
{
    ft_printf("%i\n", -1024);
    printf("%5%\n");
    ft_printf("%5%\n");
    printf("hello %s yes\n", "world");
    ft_printf("hello %s yes\n", "world");

    printf("%+7s\n", "hello");
    ft_printf("%+7s\n", "hello");

    printf("%23s\n", NULL);
    ft_printf("%23s\n", NULL);

    printf("%-17saa\n", NULL);
    ft_printf("%-17saa\n", NULL);

    printf("%-5caa\n", 'x');
    ft_printf("%-5caa\n", 'x');

    printf("{%2c}\n", 0);
    ft_printf("{%2c}\n", 0);

    printf("{%5s}\n", "\0\0\0");
    ft_printf("{%5s}\n", "\0\0\0");

    ft_printf("%i\n", -1024);
    printf("% i\n", 1024);
    printf("% i\n", -1024);
    printf("% i\n", 102456);

    printf("% i\n", 1);
    printf("% i\n", -1);
    printf("% 3i\n", 1);
    printf("% 3i\n", -1);
    printf("%3i\n", 1);
    printf("%3i\n", -1);


    ft_printf("% i\n", 1);
    ft_printf("% i\n", -1);
    ft_printf("% 3i\n", 1);
    ft_printf("% 3i\n", -1);
    ft_printf("%3i\n", 1);
    ft_printf("%3i\n", -1);

    printf("%+d\n", 1024);
    printf("%+d\n", -1024);
    printf("%+d\n", 0);
    ft_printf("%+d\n", 1024);
    ft_printf("%+d\n", -1024);
    ft_printf("%+d\n", 0);

    printf("%-x\n", 42);
    ft_printf("%-x\n", 42);

    printf("{%06d}\n", 10000);
    ft_printf("{%06d}\n", 10000);
    //ft_printf("{%030d}", 10000);
    printf("%07i\n", -54);
    ft_printf("%07i\n", -54);

    printf("%04i\n", -4825);
    ft_printf("%04i\n", -4825);

    printf("{%+03d}\n", 0);
    ft_printf("{%+03d}\n", 0);
}

