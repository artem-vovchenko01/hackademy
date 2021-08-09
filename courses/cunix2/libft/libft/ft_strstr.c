#include "libft.h"
int match_exclude_null(const char *str, const char *sub);

char *strstr(const char *str, const char *sub)
{
    size_t cmp_len = ft_strlen(str) - ft_strlen(sub) + 1;
    for (size_t i = 0; i < cmp_len; i++)
    {
        if (match_exclude_null(str, sub))
        {
            return (char *) str;
        }
    }
    return NULL;
}

int match_exclude_null(const char *str, const char *sub)
{
    while (*str == *sub && *str != '\0')
    {
        str++;
        sub++;
    }
    if (*sub == '\0')
    {
        return 1;
    }
    return 0;
}

