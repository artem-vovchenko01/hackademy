#include <stdio.h>
#include <unistd.h>

int my_puts(const char *str)
{
    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    return 0;
}
