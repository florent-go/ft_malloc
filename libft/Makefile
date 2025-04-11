# Makefile pour libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:srcs/%.c=objs/%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f objs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re