#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char         *my_strcat_and_realloc(char *line, int b_read, int *line_size) {
    int             cpt;
    char            *tmp;

    (*line_size) = -1;
    cpt = -1;
    while (line[++(*line_size)]);
    tmp = line;
    if (!(line = malloc(sizeof(char) * (b_read + (*line_size) + 1)))) {
        return (NULL);
    }
    while (tmp[++cpt]) {
        line[cpt] = tmp[cpt];
    }
    free(tmp);
    return (line);
}

static boolean      find_line(char buffer[BUFFER_SIZE], char **line, int b_read, int *char_copied) {
    int             line_size;

    line_size = 0;
    if (!(*line)) {
        *line = malloc(sizeof(char) * (b_read + 1));
    }
    else {
        (*line) = my_strcat_and_realloc(*line, b_read, &line_size);
    }
    if (!(*line)) {
        return (ERROR);
    }
    while (buffer[++(*char_copied)]) {
        (*line)[++line_size - 1] = buffer[*(char_copied)];
        if (buffer[*(char_copied)] == '\n') {
            (*line)[line_size - 1] = '\0';
            return (TRUE);
        }
    }
    *(char_copied) = -1;
    (*line)[line_size] = '\0';
    return (FALSE);
}

char                *get_next_line(const int fd) {
    static char     buffer[BUFFER_SIZE + 1] = { "\0" };
    static int      char_copied = -1;
    char            *line;
    int             b_read;
    int             ret;

    line = NULL;
    if (char_copied != -1) {
        if (!find_line(buffer, &line, BUFFER_SIZE, &char_copied)) {
            return (line);
        }
    }
    while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[b_read + 1] = '\0';
        ret = find_line(buffer, &line, b_read, &char_copied);
        if (ret == TRUE || ret == ERROR) {
            return (line);
        }
    }
    if (line)
        free(line);
    return (NULL);
}
