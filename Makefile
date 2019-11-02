NAME = fractol

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

O_DIR = objects/
C_DIR = src/

LIB_FT_DIR = libft/
LIB_FT_FILE = $(LIB_FT_DIR)/libft.a

LIB_X_DIR = minilibx_macos/
LIB_X_FILE = $(LIB_X_DIR)/libtrue_mlx.a

LIB_FLAGS = -L $(LIB_X_DIR) -L $(LIB_FT_DIR) -ltrue_mlx -lft

FRAMEWORKS = -framework OpenGL -framework AppKit

#ls *.c
C_FILES_LIST = handle_mouse.c handle_keyboard_1.c handle_keyboard_2.c handle_window.c \
color_schemes.c img_pixel_put.c fract.c main.c  utilities.c \
draw_julia.c draw_mandelbrot.c \

C_FILES	= $(addprefix $(C_DIR), $(C_FILES_LIST))

O_FILES_LIST = $(patsubst %.c, %.o, $(C_FILES_LIST))
O_FILES	= $(addprefix $(O_DIR), $(O_FILES_LIST))

.PHONY: clean fclean $(LIB_FT_FILE) $(LIB_X_FILE)

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_X_FILE) $(O_DIR) $(O_FILES)
	@clang $(FLAGS) -o $(NAME) $(O_FILES) $(LIB_FLAGS) $(FRAMEWORKS)
	@echo "make: Done building \`fractol'."

$(O_DIR):
	@mkdir -p $(O_DIR)

$(LIB_FT_FILE):
	@make -C $(LIB_FT_DIR)
	@echo "make: Done building \`libft'."

$(LIB_X_FILE):
	@make -C $(LIB_X_DIR)
	@echo "make: Done building \`mlx'."

$(O_DIR)%.o: $(C_DIR)%.c
	clang $(FLAGS) -I $(INCLUDES) -I $(LIB_FT_DIR) -I $(LIB_X_DIR) -o $@ -c $<

clean:
	@make -C $(LIB_FT_DIR) clean
	@make -C $(LIB_X_DIR) clean
	@rm -rf $(O_DIR)

fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@make -C $(LIB_X_DIR) fclean
	@rm -f $(NAME)

re: fclean all