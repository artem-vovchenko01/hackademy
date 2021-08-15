#include <stdio.h>

#include "libft.h"

int main()
{
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
}

