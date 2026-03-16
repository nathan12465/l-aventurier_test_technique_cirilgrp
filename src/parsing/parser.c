/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

static int base_coordinate(char *file, move_t *movement)
{
    int sep = FALSE;
    int i = 0;

    for (i = 0; file[i] && file[i] != '\n'; i++){
        if (file[i] == ',' && sep == FALSE){
            sep = TRUE;
            continue;
        }
        if (!(file[i] >= '0' && file[i] <= '9'))
            return (EXIT_FAILURE);
        if (sep == FALSE)
            movement->current_x = (movement->current_x * 10) + file[i] - '0';
        if (sep == TRUE)
            movement->current_y = (movement->current_y * 10) + file[i] - '0';
    }
    if (sep == FALSE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int check_movement(char *move_line)
{
    if (move_line[0] == '\n' || move_line[0] == '\0')
        return (EXIT_FAILURE);
    for (int i = 0; move_line[i] && move_line[i] != '\n'; i++)
        if (move_line[i] != 'N' && move_line[i] != 'S'
             && move_line[i] != 'E' && move_line[i] != 'O')
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int movement_parsing(char *filename, move_t *movement, error_t *error)
{
    char *file = read_file(filename);
    int i = 0;

    if (!file){
        *error = EFILE;
        return (EXIT_FAILURE);
    }
    if (base_coordinate(file, movement) == EXIT_FAILURE){
        *error = INVCONFCORD;
        free(file);
        return (EXIT_FAILURE);
    }
    while (file[i] && file[i] != '\n')
        i++;
    if (!file[i]){
        free(file);
        return (EXIT_FAILURE);
    }
    i++;
    movement->move_line = strdup(&file[i]);
    if (check_movement(movement->move_line) == EXIT_FAILURE){
        *error = INVCONFMOVE;
        free(movement->move_line);
        free(file);
        return (EXIT_FAILURE);
    }
    free(file);
    return (EXIT_SUCCESS);
}

int check_map_conformity(map_t *map, char *map_file, error_t *error)
{
    unsigned int buff = 0;

    for (int i = 0; map_file[i] && map_file[i] != '\n'; i++)
        map->max_x++;
    buff = map->max_x;
    map->max_x = 0;
    for (int i = 0; map_file[i]; i++){
        if (map_file[i] == '\n'){
            map->max_y++;
            if (map->max_x != buff){
                *error = INVMAP;
                return (EXIT_FAILURE);
            }
            map->max_x = 0;
            i++;
        }
        if (map_file[i] != '\0' && map_file[i] != '\n' && map_file[i] != '\r' && map_file[i] != '#' && map_file[i] != ' '){
            *error = INVMAPC;
            return (EXIT_FAILURE);
        }
        map->max_x++;
    }
    return (EXIT_SUCCESS);
}

int map_parsing(char *filename, map_t *map, error_t *error)
{
    char *file = read_file(filename);

    if (!file){
        *error = EFILE_MAP;
        return (EXIT_FAILURE);
    }
    if (check_map_conformity(map, file, error) == EXIT_FAILURE){
        free(file);
        return (EXIT_FAILURE);
    }
    free(file);
    return (EXIT_SUCCESS);
}

int parser(config_t *config, char *settings_f, char *map_f)
{
    if (movement_parsing(settings_f, &config->move, &config->error) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (map_parsing(map_f, &config->map, &config->error) == EXIT_FAILURE){
        free(config->move.move_line);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
