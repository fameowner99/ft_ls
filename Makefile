NAME = ft_ls

CC = gcc

FLAGS = 

RM = rm -f

SRC = srcs/main.c srcs/ft_ls.c srcs/flag_tools.c srcs/parsing.c srcs/manage_list_container.c \
		srcs/sort_list.c srcs/main_part.c srcs/print_container.c srcs/manage_data_container.c \
			srcs/print_directory.c

LIB_DIR = libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) all
	$(CC) $(FLAGS) $(OBJ) -o $@ -L./libft/ -lft 
	@echo "ft_ls done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
