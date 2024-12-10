CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c
HEADER = ft_printf.h 

OBJ_FILES = $(SRC:.c=.o)

NAME = printf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "LINKING"
	$(CC) $(CFLAGS) $(OBJ_FILES) $(HEADER) -o

$(BUILD_DIR)/%.o: $(SRC)
	(CC) -I . -c $< -o $@