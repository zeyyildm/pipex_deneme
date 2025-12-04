NAME = pipex

SRCS = pipex.c pipex_utils.c paths.c null_check.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft

clean:
	$(RM) $(OBJS)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
