/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

void init_info(config_t *config)
{
    config->error = NERR;
    config->map.max_x = 0;
    config->map.max_y = 0;
    config->move.current_x = 0;
    config->move.current_y = 0;
    config->move.move_line = NULL;
}

int explorer(char *setting_f, char *map_f)
{
    config_t *config = malloc(sizeof(config_t));

    init_info(config);
    if (parser(config, setting_f, map_f) == EXIT_FAILURE){
        error_manager(&config->error, config->map);
        free(config);
        return (EXIT_FAILURE);
    }
    if (path_finder(config, map_f) == EXIT_FAILURE){
        error_manager(&config->error, config->map);
        free(config->move.move_line);
        free(config);
        return (EXIT_FAILURE);
    }
    free(config->move.move_line);
    free(config);
    return (EXIT_SUCCESS);
}
