SRC = minishell.c read.c exec.c ft_getenv.c cd.c

OBJ = $(SRC:.c=.o)

NAME = ft_sh1

CC = gcc

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft/libft.a -o $(NAME) -Wall -Wextra

re : fclean all

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
