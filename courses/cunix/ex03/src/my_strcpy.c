#include <stdio.h>

char *my_strcpy(char *dest, const char *src) 
{
    char *orig = dest;
    while ((*dest = *src) != '\0') 
    {
        src++;
        dest++;
    }
    return orig;
}
