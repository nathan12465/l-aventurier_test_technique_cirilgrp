/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

int check_exec(char **map2d, config_t *config)
{
    printf("CHECK x : %d,  y : %d\n", config->move.current_x, config->move.current_y);
    if (config->move.current_x < 0 || config->move.current_y < 0){
        config->error = LIMITLESS;
        my_free_word_array(map2d);
        return (EXIT_FAILURE);
    }
    if (config->move.current_x >= config->map.max_x){
        config->error = LIMITLESS;
        my_free_word_array(map2d);
        return (EXIT_FAILURE);
    }
    if (config->move.current_y >= config->map.max_y){
        config->error = LIMITLESS;
        my_free_word_array(map2d);
        return (EXIT_FAILURE);
    }
    if (map2d[config->move.current_y][config->move.current_x] == '#'){
        config->error = WPATH;
        my_free_word_array(map2d);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void move_exec(char c, move_t *move, map_t map)
{
    printf("prev x : %d, prev y : %d\n", move->current_x, move->current_y);
    switch (c) {
    case 'N':
        move->current_y--;
        break;
    case 'S':
        move->current_y++;
        break;
    case 'E':
        move->current_x++;
        break;
    case 'O':
        move->current_x--;
        break;
    default:
        break;
    }
}

void write_move(char **map2d, move_t move)
{
    map2d[move.current_y][move.current_x] = '.';
}

int path_finder(config_t *config, char *map)
{
    char *file = read_file(map);
    char **map2d = NULL;

    if (!file)
        return (EXIT_FAILURE);
    map2d = my_str_to_word_array(file, '\n');
    free(file);
    if (!map2d)
        return (EXIT_FAILURE);
    for (int i = 0; config->move.move_line[i]; i++){
        move_exec(config->move.move_line[i], &config->move, config->map);
        if (check_exec(map2d, config) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        write_move(map2d, config->move);
    }
    for (int i = 0; map2d[i]; i++)
        printf("%s", map2d[i]);
    my_free_word_array(map2d);
    return (EXIT_SUCCESS);
}