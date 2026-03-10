/*
##
### Ciril GROUP test:
### L'aventurier
###
##
*/

#include "explorer.h"

int open_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("error open");
        return -1;
    }
    return fd;
}

long get_file_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0)
        return -1;
    return st.st_size;
}

char *get_file_content(int fd, long size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (!buffer) {
        perror("Error malloc");
        close(fd);
        return NULL;
    }
    if (read(fd, buffer, size) != size) {
        perror("Error read");
        close(fd);
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}

char *read_file(const char *filename)
{
    int fd = open_file(filename);
    int size = get_file_size(filename);
    char *buffer = NULL;

    if (size < 0 || fd == -1) {
        return NULL;
    }
    buffer = get_file_content(fd, size);
    if (!buffer || buffer[0] == '\0')
        return NULL;
    close(fd);
    return buffer;
}
