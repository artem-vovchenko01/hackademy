#include "libft.h"

char *ft_strmap(const char *s, char (*f)(char ch))
{
    size_t len = ft_strlen(s);
    char *new_s = (char *) malloc((len + 1) * sizeof(char));
    char *res = new_s;
    while (len-- > 0)
    {
        *(new_s++) = f(*(s++));
    }
    *new_s = '\0';
    return res;
}

