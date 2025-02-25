NAME = philo

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)[BUILD] Compilando $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)[OK] ✅ Compilación de $(NAME) completada.$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(YELLOW)[BUILD] Compilando objeto: $<$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(RED)[CLEAN] Eliminando archivos objeto...$(RESET)\n"
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	@printf "$(GREEN)[OK] ✅ Limpieza completada.$(RESET)\n"

fclean: clean
	@printf "$(RED)[CLEAN] Eliminando ejecutable...$(RESET)\n"
	rm -f $(NAME)
	@printf "$(GREEN)[OK] ✅ Eliminación completada.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
