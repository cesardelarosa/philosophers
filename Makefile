NAME = philo

CC     = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR         := src
INC_DIR         := include
OBJ_DIR         := obj

ACTIONS_DIR         := $(SRC_DIR)/actions
ACTIONS_UTILS_DIR   := $(ACTIONS_DIR)/action_utils
CORE_DIR            := $(SRC_DIR)/core
MUTEX_DIR           := $(SRC_DIR)/mutex
TIMER_DIR           := $(SRC_DIR)/timer

SRC_MAIN_FILES         	= main.c
SRC_ACTIONS_FILES      	= eat.c sleep.c put_forks.c take_forks.c think.c
SRC_ACTIONS_UTILS_FILES	= check_stop.c print_state.c smart_sleep.c
SRC_CORE_FILES         	= clean_resources.c init_simulation.c parse_arguments.c run_simulation.c print_error.c
SRC_MUTEX_FILES        	= destroy_safe_mutex.c init_safe_mutex.c lock_safe_mutex.c unlock_safe_mutex.c
SRC_TIMER_FILES        	= get_time.c

SRC_MAIN         	:= $(addprefix $(SRC_DIR)/, $(SRC_MAIN_FILES))
SRC_ACTIONS      	:= $(addprefix $(ACTIONS_DIR)/, $(SRC_ACTIONS_FILES))
SRC_ACTIONS_UTILS	:= $(addprefix $(ACTIONS_UTILS_DIR)/, $(SRC_ACTIONS_UTILS_FILES))
SRC_CORE         	:= $(addprefix $(CORE_DIR)/, $(SRC_CORE_FILES))
SRC_MUTEX        	:= $(addprefix $(MUTEX_DIR)/, $(SRC_MUTEX_FILES))
SRC_TIMER        	:= $(addprefix $(TIMER_DIR)/, $(SRC_TIMER_FILES))

SRCS := $(SRC_MAIN) $(SRC_ACTIONS) $(SRC_ACTIONS_UTILS) $(SRC_CORE) $(SRC_MUTEX) $(SRC_TIMER)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[1;33m[BUILD] Linking $(NAME)...\033[0m\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "\033[1;32m[OK] ✅ Compilación de $(NAME) completada.\033[0m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "\033[1;33m[BUILD] Compilando objeto: $<\033[0m\n"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\033[1;31m[CLEAN] Eliminando archivos objeto...\033[0m\n"
	rm -rf $(OBJ_DIR)
	@printf "\033[1;32m[OK] ✅ Limpieza completada.\033[0m\n"

fclean: clean
	@printf "\033[1;31m[CLEAN] Eliminando ejecutable...\033[0m\n"
	rm -f $(NAME)
	@printf "\033[1;32m[OK] ✅ Eliminación completada.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
