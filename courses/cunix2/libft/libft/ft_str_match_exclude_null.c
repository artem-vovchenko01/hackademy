int ft_str_match_exclude_null(const char *str, const char *sub)
{
    while (*str == *sub && *str != '\0')
    {
        str++;
        sub++;
    }
    if (*sub == '\0')
    {
        return 1;
    }
    return 0;
}

