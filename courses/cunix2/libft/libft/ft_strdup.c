#include "libft.h"

char *ft_strdup(const char *str)
{
    size_t len = ft_strlen(str);
    char *dup = malloc((len + 1) * sizeof(char));
    char *res = dup;
    char ch;
    do 
    {
        *(dup++) = ch = *(str++);
    }
    while (ch != 0);
    return res;
}
