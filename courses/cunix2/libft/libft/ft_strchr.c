#include "libft.h"

char *ft_strchr(const char *str, int c)
{
    char inp_c = c;
    while (*str != inp_c)
    {
        if (*str == '\0')
        {
            return NULL;
        }
        str++;
    }
    return str;
}

