#include "libft.h"

char *ft_strtrim(const char *s)
{
    size_t inp_sz = ft_strlen(s);
    size_t white_sz = 0;
    while (*s == ' ' || *s == '\t' || *s == '\n')
    {
        s++;
        white_sz++;
    }
    char *nonwhite_begin = (char *) s;

    if (*s)
    {
        while (*s)
        {
            s++;
        }
        s--;
    }

    while (*s == ' ' || *s == '\t' || *s == '\n')
    {
        s--;
        white_sz++;
    }

    char *res_str = NULL;
    size_t res_sz = inp_sz - white_sz;
    if (!(res_str = malloc((res_sz + 1) * sizeof(char))))
    {
        return NULL;
    }
    char *ret = res_str;

    while (res_sz-- > 0)
    {
        *(res_str++) = *(nonwhite_begin++);
    }
    *res_str = '\0';
    return ret;
}
    
