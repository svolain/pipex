NAME = pipex
LIBFTDIR = ./libft
MAKE = make
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
HEAD = includes/pipex.h

SRCS = srcs/main.c \
		srcs/pipex_utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@$(MAKE) all bonus -C $(LIBFTDIR)
		@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(LIBFTDIR)

fclean:
		@rm -f $(NAME)
		@rm -f	libft.a
		@$(MAKE) fclean -C $(LIBFTDIR)

re:	fclean all

.PHONY: all clean fclean re
