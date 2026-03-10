/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

int main(int argc, char **argv)
{
    if (argc != 3){
        if (argc < 3)
            fprintf(stderr, "Pas assez d'arguments\n");
        if (argc > 3)
            fprintf(stderr, "Trop d'arguments\n");
        return (EXIT_ERROR);
    }
    if (explorer(argv[1], argv[2]) == EXIT_FAILURE)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}
