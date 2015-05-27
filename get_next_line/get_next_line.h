#ifndef     GET_NEXT_LINE_H_
# define    GET_NEXT_LINE_H_
# define    BUFFER_SIZE     10

typedef enum    boolean boolean;
enum        boolean {
        TRUE = 0,
        FALSE = 1
};

char        *get_next_line(const int fd);

#endif      /* !GET_NEXT_LINE_H_ */
