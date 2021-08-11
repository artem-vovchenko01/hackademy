#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    if (*little == '\0')
    {
        return (char *) big;
    }
    size_t search = len - ft_strlen(little) + 1;
    if (search <= 0 || len == 0)
    {
        return NULL;
    }

    for (size_t i = 0; i < search; i++)
    {
        if (ft_str_match_exclude_null(big, little))
        {
            return (char *) big;
        }
        big++;
    }
    return NULL;
}
    
