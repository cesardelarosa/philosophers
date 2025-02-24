NAME = philo_bonus

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✅ Compilación de $(NAME) completada.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)🔧 Compilando objeto: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)🧹 Limpiando archivos objeto...$(RESET)"
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✅ Limpieza completada.$(RESET)"

fclean: clean
	@echo "$(RED)🗑️ Eliminando ejecutable...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)✅ Eliminación completada.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
