#ifndef     GET_NEXT_LINE_H_
# define    GET_NEXT_LINE_H_
# define    BUFFER_SIZE     1

typedef enum    boolean boolean;
enum        boolean {
        TRUE = 0,
        FALSE = 1,
        ERROR = 2
};

char        *get_next_line(const int fd);

#endif      /* !GET_NEXT_LINE_H_ */
