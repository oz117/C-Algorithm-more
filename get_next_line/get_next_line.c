#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

static char         *my_strcat_and_realloc(char *line, int b_read, int *line_size) {
    int             cpt;
    char            *tmp;

    (*line_size) = -1;
    cpt = -1;
    while (line[++(*line_size)]);
    tmp = line;
    line = malloc(sizeof(char) * (b_read + (*line_size) + 1));
    while (tmp[++cpt]) {
        line[cpt] = tmp[cpt];
    }
    free(tmp);
    return (line);
}

static boolean      find_line(char buffer[BUFFER_SIZE], char **line, int b_read) {
    int             i;
    int             line_size;

    i = -1;
    line_size = 0;
    if (!(*line)) {
        *line = malloc(sizeof(char) * (b_read + 1));
    }
    else {
        (*line) = my_strcat_and_realloc(*line, b_read, &line_size);
    }
    while (buffer[++i]) {
        (*line)[++line_size - 1] = buffer[i];
        if (buffer[i] == '\n') {
            (*line)[line_size - 1] = '\0';
            return (TRUE);
        }
    }
    (*line)[line_size] = '\0';
    return (FALSE);
}

char                *get_next_line(const int fd) {
    static char     buffer[BUFFER_SIZE + 1] = { "\0" };
    char            *line;
    int             b_read;

    line = NULL;
    while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[b_read + 1] = '\0';
        if (!find_line(buffer, &line, b_read)) {
            return (line);
        }
    }
    return (NULL);
}
