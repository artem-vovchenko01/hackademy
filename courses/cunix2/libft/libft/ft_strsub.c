#include "libft.h"

char *ft_strsub(const char *s, unsigned int start, size_t len)
{
    char *new_s; 
    size_t inp_len = ft_strlen(s);
    size_t mem_size = len;
    if (len > inp_len - start)
    {
        mem_size = inp_len - start;
    }
    if (!(new_s = (char *) malloc((mem_size + 1) * sizeof(char))))
    {
        return NULL;
    }
    char *res = new_s;
    while (start-- > 0)
    {
        if (! *s)
        {
            free(new_s);
            return NULL;
        }
        s++;
    }

    while (len-- > 0)
    {
        if (*s == '\0')
        {
            break;
        }
        *(new_s++) = *(s++);
    }
    *new_s = '\0';
    return res;
}
