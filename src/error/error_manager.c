/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

void error_manager(error_t *error)
{
    switch (*error)
    {
        case NERR:
            break;
        case INVCONFCORD:
            fprintf(stderr, "Les coordonnées de départ sont invalides\n");
            break;
        case INVCONFMOVE:
            fprintf(stderr, "Les déplacement ne sont pas conforme : rappel : N,S,E,O\n");
            break;
        case EFILE:
            fprintf(stderr, "Le fichier de configuration est vide :)\n");
            break;
        case WPATH:
            fprintf(stderr, "Chemin impossible\n");
            break;
        default:
            break;
    }
}
