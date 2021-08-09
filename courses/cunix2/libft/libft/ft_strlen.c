#include "libft.h"

size_t ft_strlen(const char *str)
{
    size_t sz;
    for (sz = 0; * (str++) != '\0'; sz++)
        ;
    return sz;
}
