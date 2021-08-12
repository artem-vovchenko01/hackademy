#include "libft.h"

size_t get_split_word_number(char *s, char c);
void allocate_words_memory(char **arr, size_t n, char *s, char c);
void populate_words(char **arr, size_t n, char *s, char c);

char **ft_strsplit(const char *s, char c)
{
    size_t words = get_split_word_number((char *) s, c);

    // Allocating the array of pointers to words
    char **words_arr = (char **) malloc((words + 1) * sizeof(char *));

    // Allocating memory for each word
    allocate_words_memory(words_arr, words, (char *) s, c);

    // Populating each word
    populate_words(words_arr, words, (char *) s, c);

    return words_arr;
}

size_t get_split_word_number(char *s, char c)
{
    char *cur_chr = (char *) s;
    int matched = 1;
    size_t words = 0;

    while (*cur_chr)
    {
        if (*(cur_chr++) == c)
        {
            matched = 1;
        }
        else
        {
            if (matched)
            {
                words++;
            }
            matched = 0;
        }
    }
    return words;
}

void allocate_words_memory(char **arr, size_t n, char *s, char c)
{
    size_t words_iter;
    size_t word_len;
    char *new_word = NULL;
    for (words_iter = 0; words_iter < n; words_iter++)
    {
        word_len = 0;
        while (*s == c)
        {
            s++;
        }

        while (*s != c && *s != '\0')
        {
            word_len++;
            s++;
        }
        new_word = (char *) malloc((word_len + 1) * sizeof(char));
        arr[words_iter] = new_word;
    }
    arr[++words_iter] = NULL;
}

void populate_words(char **arr, size_t n, char *s, char c)
{
    size_t words_iter;
    char *cur_word_ptr;
    for (words_iter = 0; words_iter < n; words_iter++)
    {
        cur_word_ptr = arr[words_iter];
        while (*s == c)
        {
            s++;
        }
        while (*s != c && *s != '\0')
        {
            *(cur_word_ptr++) = *s;
            s++;
        }
    }
}
