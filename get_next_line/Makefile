NAME		=	get_next_line

ERRLOG		=	2>> errors~

CC			=	gcc
RM			=	rm -rf
ECHO		=	echo

FLAGS		=	-W -Wall -Werror -Wextra -g3
#			-lasan				\
			-fsanitize=address		\
			-fno-omit-frame-pointer		\
			-O0
#DEBUG		=	-g -g3 -ggdb

DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

INCLUDE		=	-I./

ENTRYPOINT	=	$(wildcard ./*.c)

FILE		=	$(ENTRYPOINT)

OBJ			=	$(FILE:.c=.o)

## Compile ---------------------------------------------------------------------
all:		temp $(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(INCLUDE) $(OBJ) -o $(NAME) $(LIBRARY) \
		 $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $@ $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $@ $(DEFAULT)
.c.o:
		@$(CC) -c $(INCLUDE) $< -o $@ $(DEBUG) $(FLAGS) \
		 $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

## Misc ------------------------------------------------------------------------
temp:
		@find . -name "*~" -delete
clean:		temp
		@$(RM) $(OBJ)
fclean:		clean
		@$(RM) $(NAME)
re:		fclean all
