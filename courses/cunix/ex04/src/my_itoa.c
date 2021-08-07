#include <stdio.h>
char *my_itoa(int val)
{
    char temp[20];
    int pos_temp = 0, pos_res = 0;
    static char res[20];
    int count = 0;
    if (val < 0)
    {
        val *= -1;
        res[pos_res++] = '-';
    }
    do
    {
        temp[pos_temp++] = val % 10 + '0';
        val /= 10;
        count++;
    } while (val > 0);

    while (count-- > 0)
    {
        res[pos_res++] = temp[--pos_temp];
    }
    res[pos_res] = '\0';
    return res;
}

