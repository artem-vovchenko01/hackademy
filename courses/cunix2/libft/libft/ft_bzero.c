#include "libft.h"

void ft_bzero(void *s, size_t len)
{
    while (len-- > 0)
    {
        *(char *)(s++) = 0;
    }
}

