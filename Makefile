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

NAME		=	push_swap
BONUS_NAME	=	checker

PUSH_SWAP_DIR	=	push_swap_srcs
CHECKER_DIR	=	checker_srcs
PUSH_SWAP_OBJ_DIR = ./push_swap_obj
CHECKER_OBJ_DIR = ./checker_obj
SRCS		=	$(wildcard $(PUSH_SWAP_DIR)/*.c)
OBJS		=	$(addprefix $(PUSH_SWAP_OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))
BONUS_SRCS	=	$(wildcard $(CHECKER_DIR)/*.c)
BONUS_OBJS	=	$(addprefix $(CHECKER_OBJ_DIR)/,$(notdir $(BONUS_SRCS:.c=.o)))

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm
RMFLAGS		=	-rf

FTPRINTF_DIR	=	./ft_printf
FTPRINTF_LIB	=	libftprintf.a
FTPRINTF		=	$(FTPRINTF_DIR)/$(FTPRINTF_LIB)

TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER		=	./ps_tester.pl

$(PUSH_SWAP_OBJ_DIR):
	mkdir -p $(PUSH_SWAP_OBJ_DIR)

$(CHECKER_OBJ_DIR):
	mkdir -p $(CHECKER_OBJ_DIR)

$(NAME): $(FTPRINTF) $(PUSH_SWAP_OBJ_DIR) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FTPRINTF)

$(BONUS_NAME): $(FTPRINTF) $(CHECKER_OBJ_DIR) $(BONUS_OBJS)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) $(FTPRINTF)


$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

bonus:	$(BONUS_NAME)

clean:
	$(RM) $(RMFLAGS) $(PUSH_SWAP_OBJ_DIR)
	$(RM) $(RMFLAGS) $(CHECKER_OBJ_DIR)
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(BONUS_NAME)
	make -C $(FTPRINTF_DIR) fclean

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

.PHONY: all bonus clean fclean testclean re reb vis 3 5 100 500