NAME = explorer

CC = clang

ROOT_DIR = ./

INCLUDE_D = $(ROOT_DIR)include/

SRC_D = $(ROOT_DIR)src/
OBJ_D = $(ROOT_DIR)obj/

CFLAGS = -I$(INCLUDE_D) -g3 -Wall -Wextra

EXPLORER_D = $(SRC_D)explorer/

PARSING_D = $(SRC_D)parsing/

UTILS_D = $(SRC_D)utils/

ERROR_D = $(SRC_D)error/

EXPLORER_F = explorer.c

PARSING_F = parser.c

UTILS_F = read_file.c \
          my_str_to_word_array.c

ERROR_F = error_manager.c

SRC = $(addprefix $(SRC_D), main.c) \
      $(addprefix $(UTILS_D), $(UTILS_F)) \
      $(addprefix $(EXPLORER_D), $(EXPLORER_F)) \
      $(addprefix $(PARSING_D), $(PARSING_F)) \
      $(addprefix $(ERROR_D), $(ERROR_F))

OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all	clean fclean re