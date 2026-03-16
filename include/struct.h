/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef enum error_s {
    EFILE, // empty file
    EFILE_MAP, // map file is empty
    WPATH, // wrong path
    INVCONFCORD, // invalid coordinate in configuration file
    INVCONFMOVE, // invalid movement in configuration file
    INVMAP, // invalid map configuration
    INVMAPC, // invalid char in map configuration
    LIMITLESS, // sans limite (hors limite de la map)
    NERR // no error;
}error_t;

typedef struct map_s {
    unsigned int max_y;
    unsigned int max_x;
}map_t;

typedef struct move_s {
    char *move_line;
    unsigned int current_y;
    unsigned int current_x;
}move_t;

typedef struct information_s {
    map_t map;
    move_t move;
    error_t error;
}config_t;

#endif
