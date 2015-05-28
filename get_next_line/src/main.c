#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int         main(int __attribute__((unused)) ac, char __attribute__((unused)) **av) {
    char    *s;
    int     fd;

    s = NULL;
    if ((fd = open("./gcc", O_RDONLY)) == -1) {
        fprintf(stderr, "Open failed");
        return (EXIT_FAILURE);
    }
    while ((s = get_next_line(fd))) {
        write(STDOUT_FILENO, s, strlen(s));
        write(STDOUT_FILENO, "\n", sizeof(char) * 1);
        free(s);
    }
    return (EXIT_SUCCESS);
}
