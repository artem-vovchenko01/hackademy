#include "libft.h"

void *ft_memset(void *s, int c, size_t len)
{
    void *ret = s;
    unsigned char *p = s;
    while (len-- > 0)
    {
        *(p++) = c;
    }
    return ret;
}

