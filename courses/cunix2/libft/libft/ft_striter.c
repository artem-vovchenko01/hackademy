void ft_striter(char *str, void (*f)(char *))
{
    while (*str != '\0')
    {
        f(str);
        str++;
    }
}
