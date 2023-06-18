# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 15:20:35 by ofadahun          #+#    #+#              #
#    Updated: 2023/05/31 10:32:44 by ofadahun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=	push_swap
CHECKER	=	checker

PUSH_SWAP_DIR	=	./push_swap_program
CHECKER_DIR	=	./checker_program
PUSH_SWAP_OBJ_DIR = ./push_swap_obj
CHECKER_OBJ_DIR = ./checker_obj
PUSH_SWAP_SRCS		=	$(wildcard $(PUSH_SWAP_DIR)/*.c)
PUSH_SWAP_OBJS		=	$(addprefix $(PUSH_SWAP_OBJ_DIR)/,$(notdir $(PUSH_SWAP_SRCS:.c=.o)))
CHECKER_SRCS	=	$(wildcard $(CHECKER_DIR)/*.c)
CHECKER_OBJS	=	$(addprefix $(CHECKER_OBJ_DIR)/,$(notdir $(CHECKER_SRCS:.c=.o)))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm
RMFLAGS		=	-rf

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER		=	./ps_tester.pl

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP_OBJ_DIR):
	mkdir -p $(PUSH_SWAP_OBJ_DIR)

$(CHECKER_OBJ_DIR):
	mkdir -p $(CHECKER_OBJ_DIR)

$(PUSH_SWAP): $(LIBFT) $(PUSH_SWAP_OBJ_DIR) $(PUSH_SWAP_OBJS)
	$(CC) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS) $(LIBFT)

$(CHECKER): $(LIBFT) $(CHECKER_OBJ_DIR) $(CHECKER_OBJS)
	$(CC) -o $(CHECKER) $(CHECKER_OBJS) $(LIBFT)


$(LIBFT):
	if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone https://github.com/Kingsolomon445/42_libft libft; \
	fi
	make -C $(LIBFT_DIR) all

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(RMFLAGS) $(PUSH_SWAP_OBJ_DIR)
	$(RM) $(RMFLAGS) $(CHECKER_OBJ_DIR)
	if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	$(RM) $(RMFLAGS) $(PUSH_SWAP)
	$(RM) $(RMFLAGS) $(CHECKER)
	if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) fclean; \
	fi

testclean: 
	$(RM) $(RMFLAGS) .push_swap_test_results.log imgui.ini push_swap_run_args.log


re: fclean all

reb: fclean bonus

$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)

3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100

5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100

100: $(NAME) $(TESTER)
	perl $(TESTER) 100 500

500: $(NAME) $(TESTER)
	perl $(TESTER) 500 300

.PHONY: all clean fclean testclean re reb vis 3 5 100 500