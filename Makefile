include libft.mk

SRC_DIR    = ./src
INC_DIR    = ./include
OBJ_DIR    = ./obj

RAW_SRC    := $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS:= $(shell find $(SRC_DIR) -mindepth 1 -type d)
SRCDIRS = $(RAW_DIRS:./src/%=%)
SRC        = $(RAW_SRC:./src/%=%)
OBJ        = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC        = gcc
CFLAGS    = -Wall -Wextra -Werror

.PHONY: all clean fclean re
.PRECIOUS: auteur libft.mk

all: $(NAME)

$(NAME):
	@$(MAKE) $(OBJ_DIR) --no-print-directory
	@$(MAKE) $(FT_NAME) --no-print-directory

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(addprefix $(OBJ_DIR)/,$(SRCDIRS))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(FT_NAME): $(OBJ)
	ar rc $(FT_NAME) $(OBJ)
	ranlib $(FT_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT_NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
