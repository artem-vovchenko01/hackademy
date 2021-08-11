#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    void *ret = dest;
    unsigned char *dest_p = dest;
    unsigned char *src_p = (void *) src;
    while (n-- > 0)
    {
        if (*src_p == c)
        {
            break;
        }
        *dest_p = *src_p;
    }
    return ret;
}
