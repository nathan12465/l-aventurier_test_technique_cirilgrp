/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#ifndef EXPLORER_H
    #define EXPLORER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #include "struct.h"

    #define EXIT_ERROR 84
    #define TRUE 1
    #define FALSE 0

int explorer(char *settings_f, char *map_f);

int parser(config_t *config, char *settings_f, char *map_f);

int path_finder(config_t *config, char *map);

char *read_file(const char *filename);
char **my_str_to_word_array(char *str, char sep);
void my_free_word_array(char **word_array);

void error_manager(error_t *error, map_t map);

#endif
