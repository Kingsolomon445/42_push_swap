NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS =	rcs
RM		=	rm -rf

SRC		=	ft_check_specifier ft_printer_one ft_printer_two ft_printf_utils_one ft_printf_utils_two ft_printf
SRCS 	=	$(addsuffix .c, $(SRC))

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

bonus:	all

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
	cp	$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re