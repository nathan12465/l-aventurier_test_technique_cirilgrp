/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

void write_move(char **map2d, move_t move, int state)
{
    if (state == 0)
        map2d[move.current_y][move.current_x] = '.';
    if (state == 1)
        map2d[move.current_y][move.current_x] = 'X';
    if (state == 2)
        map2d[move.current_y][move.current_x] = 'S';
    if (state == 3)
        map2d[move.current_y][move.current_x] = 'E';
}

void print_map(map_t map, char **map2d)
{
    for (unsigned int i = 0; i < map.max_y; i++)
        printf("%s\n", map2d[i]);
}

int check_exec(char **map2d, config_t *config)
{
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
        write_move(map2d, config->move, 1);
        print_map(config->map, map2d);
        my_free_word_array(map2d);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void move_exec(char c, move_t *move)
{
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
        if (i == 0 && check_exec(map2d, config) == EXIT_SUCCESS)
            write_move(map2d, config->move, 2);
        move_exec(config->move.move_line[i], &config->move);
        if (check_exec(map2d, config) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        write_move(map2d, config->move, 0);
    }
    if (check_exec(map2d, config) == EXIT_SUCCESS)
        write_move(map2d, config->move, 3);
    print_map(config->map, map2d);
    my_free_word_array(map2d);
    return (EXIT_SUCCESS);
}
