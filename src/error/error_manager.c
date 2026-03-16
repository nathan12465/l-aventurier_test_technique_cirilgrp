/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

void error_manager(error_t *error, map_t map)
{
    switch (*error)
    {
        case NERR:
            break;
        case INVCONFCORD:
            fprintf(stderr, "Les coordonnées de départ sont invalides\n");
            break;
        case INVCONFMOVE:
            fprintf(stderr, "Les déplacement ne sont pas conforme : rappel : 'N','S','E','O'\n");
            break;
        case EFILE:
            fprintf(stderr, "Le fichier de configuration est vide :)\n");
            break;
        case EFILE_MAP:
            fprintf(stderr, "Pas de carte :)\n");
            break;
        case INVMAP:
            fprintf(stderr, "Mauvaise configuration de map\n");
            break;
        case INVMAPC:
            fprintf(stderr, "Caractère non autorisé dans la map : rappel : '#',' '\n");
            break;
        case WPATH:
            fprintf(stderr, "Chemin impossible\n");
            break;
        case LIMITLESS:
            fprintf(stderr, "Chemin en dehors des limites : rappel : Xmax = %d, Ymax = %d\n", map.max_x, map.max_y);
            break;
        default:
            break;
    }
}
