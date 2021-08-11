#include <stdlib.h>
#include <stddef.h>

// Day 1
void ft_bzero(void *s, size_t len);
char *ft_strdup(const char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *str, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);

// Day 2
int abs(int i);
div_t div(int num, int denom);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *big, const char *little, size_t len);
void *ft_memset(void *s, int c, size_t len);

// Utility functions

int ft_str_match_exclude_null(const char *str, const char *sub);
size_t ft_strlen(const char *s);
