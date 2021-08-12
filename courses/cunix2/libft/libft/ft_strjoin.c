#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t len_s1 = ft_strlen(s1);
    size_t len_s2 = ft_strlen(s2);
    char *new_s = NULL;
    if (!(new_s = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char))))
    {
        return NULL;
    }
    char *res = new_s;
    while (*s1)
    {
        *(new_s++) = *(s1++);
    }

    while (*s2)
    {
        *(new_s++) = *(s2++);
    }
    *new_s = '\0';
    return res;
}

