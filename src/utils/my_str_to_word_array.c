/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** transform an str into an array of word (char**)
*/

#include "explorer.h"

static char **malloc_my_double_pointer(char *str, char sep, int word_nb)
{
    char **result = NULL;
    int word_size = 0;
    int j = 0;

    result = malloc(sizeof(char *) * (word_nb + 1));
    if (!result)
        return (NULL);
    for (int i = 0; i < word_nb; i++){
        word_size = 0;
        while (str[j] && str[j] != sep){
            word_size++;
            j++;
        }
        result[i] = malloc(sizeof(char) * (word_size + 1));
        if (!result[i])
            return (NULL);
        j++;
    }
    result[word_nb] = NULL;
    return (result);
}

int count_potential_word(char *str, char sep)
{
    int result = 1;

    if (!str || str[0] == '\0')
        return (0);
    for (int i = 0; str[i]; i++)
        if (str[i] == sep)
            result++;
    return (result);
}

char **my_str_to_word_array(char *str, char sep)
{
    char **result = NULL;
    int word_nb = count_potential_word(str, sep);
    int j = 0;
    int k = 0;

    if (word_nb == 0)
        return (NULL);
    result = malloc_my_double_pointer(str, sep, word_nb);
    for (int i = 0; i < word_nb; i++) {
        j = 0;
        while (str[k] && str[k] != sep) {
            result[i][j] = str[k];
            j++;
            k++;
        }
        result[i][j] = '\0';
        if (str[k] == sep)
            k++;
    }
    return (result);
}
