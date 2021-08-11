#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    void *ret = (void *) dest;
    unsigned char *dest_p =  dest;
    unsigned char *src_p = (void *)src;
    while (n-- > 0)
    {
        *(dest_p++) = *(src_p++);
    }
    return ret;
}
