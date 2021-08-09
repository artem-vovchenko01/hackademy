#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    char *last = NULL;
    char inp_c = (char) c;
    char cur_c;
    while ((cur_c = *str) != '\0')
    {
        if (cur_c == inp_c)
        {
            last = (char *) str;
        }
        str++;
    }
    if (inp_c == '\0')
    {
        return (char *) str;
    }
    return last;
}
