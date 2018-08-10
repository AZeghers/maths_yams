##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

CC	=	gcc

SRCS	=	$(shell find src -type f -name "*.c")

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-I./include -Wall -Wextra -Werror

NAME	=	201yams

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
