#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char ch_cast = (unsigned char) c;
    unsigned char *ptr = (void *) s;
    while (n-- > 0)
    {
        if (*ptr == ch_cast)
        {
            return (void *) ptr;
        }
        ptr++;
    }
    return NULL;
}
