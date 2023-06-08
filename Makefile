#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hflohil- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 14:00:44 by hflohil-      #+#    #+#                  #
#    Updated: 2023/03/09 13:07:39 by hflohil-      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME    = push_swap
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

SRC_PATH    =   src/
OBJ_PATH    =   obj/

SRC         =	push_swap.c stack_operations.c int_tools.c test_tools.c list_tools.c more_list_tools.c small_sort.c dup_checker.c free_list.c
SRCS        =   $(addprefix, $(SRC_PATH), $(SRC))

OBJ         =   $(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

INC         =   -I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
