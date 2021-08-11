#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    void *ret = dest;
    unsigned char buf[n];
    unsigned char *dest_p = dest;
    unsigned char *src_p = (void *) src;
    for (size_t i = 0; i < n; i++)
    {
        buf[i] = *(src_p++);
    }

    for (size_t i = 0; i < n; i++)
    {
        *(dest_p++) = buf[i];
    }
    return ret;
}
