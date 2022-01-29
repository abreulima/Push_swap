
# NAME =  push_swap.a

# LIST = 	

# HEADER	=	 push_swap.h

# OBJ = $(patsubst %.c, %.o, $(LIST))

# FLAGS = -Wall -Werror -Wextra -I${HEADER}

# all: $(NAME)

# $(NAME): 	$(OBJ) ${HEADER}
# 			ar rcs $(NAME) $?

# %.o : %.c 	${HEADER}
# 			gcc $(FLAGS) -c $< -o $@

# clean:
# 			rm -f $(OBJ)

# fclean:		clean
# 			rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


FLAGS = -Wall -Werror -Wextra

all:
	gcc push_swap.c $(FLAGS) -o push_swap