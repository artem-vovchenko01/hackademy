#include "libft.h"

div_t ft_div(int num, int denom)
{
    div_t res;
    res.quot = num / denom;
    res.rem = num % denom;
    return res;
}
