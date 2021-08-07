#include <stdio.h>

int my_puts(const char *str)
{
    char ch;
    while ((ch = *(str++)) != '\0')
    {
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
