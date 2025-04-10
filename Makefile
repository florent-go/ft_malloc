ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK = libft_malloc.so

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -shared

SRCS_DIR = srcs/
OBJS_DIR = objs/
INC_DIR = includes/ 

SRCS = $(wildcard $(SRCS_DIR)*.c)

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

INC := $(addprefix -I, $(INC_DIR))

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	ln -sf $@ $(SYMLINK)
	echo "✅ Compilation terminée : $(NAME)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INC)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Nettoyage des fichiers objets."

fclean: clean
	@rm -rf $(NAME) $(SYMLINK)
	@echo "🚮 Suppression complète."

re: fclean all

.PHONY: all clean fclean re
