CC		= cc

DEBUG	= false

RM		= rm -f

SRCS	= main.c		\
		  quickSort.c

OBJS	= $(SRCS:.c=.o)

NAME	= quickSort

CFLAGS	= -W -Wall -Wextra -Werror

ifeq ($(DEBUG), yes)
	CFLAGS	+= -g3
endif

all		: $(NAME)

$(NAME)	: $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all
