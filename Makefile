NAME = pipex
LIBFTDIR = ./libft
LIBFTA = ./libft/libft.a
MAKE = make
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = includes/pipex.h

SRCS = srcs/main.c \
		srcs/pipex_utils.c

SRCS_BONUS = bonus/main_bonus.c \
				bonus/pipex_utils_bonus.c

all : $(NAME)

bonus: .bonus

$(NAME) : $(LIBFTA)
		$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a -o $(NAME)

$(LIBFTA):
		@$(MAKE) all -C $(LIBFTDIR)

clean:
		@rm -f $(OBJS)
		@$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
		@rm -f $(NAME)
		@rm -f	libft.a

re:	fclean all

.bonus:
		$(CC) $(CFLAGS) $(SRCS_BONUS) ./libft/libft.a -o $(NAME) 

.PHONY: all clean fclean re
