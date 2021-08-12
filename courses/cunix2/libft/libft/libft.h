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
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);

// Day 3
void ft_striter(char *str, void (*f)(char *));
char *ft_strmap(const char *s, char (*f)(char));

// Utility functions

int ft_str_match_exclude_null(const char *str, const char *sub);
size_t ft_strlen(const char *s);
