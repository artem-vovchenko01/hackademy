#include "libft.h"

void print_buf(char *buf, int align)
{
    int pad = 0;
    size_t len = my_strlen(buf);
    if (!buf)
        len = 6;
    if (align < 0)
    {
        align *= -1;
        if (buf)
            write(1, buf, len);
        else
            write(1, "(null)", 6);
        pad = align - len;
        if (pad < 0)
            pad = 0;
        while (pad--)
        {
            write(1, " ", 1);
        }
    }
    else
    {
        pad = align - len;
        if (pad < 0)
            pad = 0;
        while (pad--)
        {
            write(1, " ", 1);
        }
        if (buf)
            write(1, buf, len);
        else
            write(1, "(null)", 6);
    }
}

int ft_printf(char *format, ...)
{
    va_list list;
    va_start(list, format);
    int num = 0;
    int format_mode = 0;
    int align_len = 0;
    int plus_found = 0, minus_found = 0, number_found = 0;
    char *str_buf = NULL;
    while (*format)
    {
        if (format_mode)
        {
            switch (*format)
            {
                case '%':
                    write(1, "%", 1);
                    format_mode = 0;
                    break;
                case 'd':
                case 'i':
                    num = va_arg(list, int);
                    print_buf(my_itoa(num), align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case 's':
                    print_buf(va_arg(list, char *), align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case 'c':
                    str_buf = malloc(2 * sizeof(char));
                    str_buf[0] = va_arg(list, int);
                    str_buf[1] = '\0';
                    print_buf(str_buf, align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case '+':
                    plus_found = 1;
                    break;
                case '-':
                    minus_found = 1;
                    break;
                default:
                    if (*format < 48 || *format > 59)
                    {
                        write(1, format, 1);
                        format_mode = 0;
                    }
                    else
                    {
                        if (!number_found)
                        {
                            number_found = 1;
                            if (minus_found)
                            {
                                align_len = (-1) * my_atoi(format);
                                minus_found = 0;
                            }
                            else if (plus_found || number_found)
                            {
                                align_len = my_atoi(format);
                                plus_found = 0;
                            }
                        }
                    }
                    break;
            }
        }
        else
        {
            if (*format == '%')
            {
                format_mode = 1;
            }
            else
            {
                write(1, format, 1);
            }
        }
        format++;
    }
    va_end(list);
    return 0;
}

