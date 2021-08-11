#include "libft.h"

char *ft_strstr(const char *str, const char *sub)
{
    size_t cmp_len = ft_strlen(str) - ft_strlen(sub) + 1;
    for (size_t i = 0; i < cmp_len; i++)
    {
        if (ft_str_match_exclude_null(str, sub))
        {
            return (char *) str;
        }
        str++;
    }
    return NULL;
}
