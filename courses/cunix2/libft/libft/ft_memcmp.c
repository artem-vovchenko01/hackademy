#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *p1 = (void *) s1;
    unsigned char *p2 = (void *) s2;

    while (*p1 == *p2 && n > 0)
    {
        n--;
        p1++;
        p2++;
    }
    
    if (n == 0)
    {
        return 0;
    }
    else 
    {
        if (*p1 > *p2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}


