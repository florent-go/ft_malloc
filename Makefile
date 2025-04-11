ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME     := libft_malloc_$(HOSTTYPE).so
SYMLINK  := libft_malloc.so

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -fPIC
LDFLAGS := -shared
INC     := -Iincludes -Ilibft/includes

SRC_DIRS := srcs libft/srcs
SRCS := $(shell find $(SRC_DIRS) -type f -name '*.c')
OBJS := $(patsubst %.c, objs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	ln -sf $@ $(SYMLINK)
	@echo "✅ Compilation terminée : $@"

objs/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf objs
	@echo "🧹 Nettoyage des .o terminé."

fclean: clean
	rm -f $(NAME) $(SYMLINK)
	@echo "🧨 Suppression complète."

re: fclean all

.PHONY: all clean fclean re
