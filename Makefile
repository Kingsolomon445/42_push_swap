# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 15:20:35 by ofadahun          #+#    #+#              #
#    Updated: 2023/05/23 14:18:54 by ofadahun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap


SRCS		=	$(wildcard *.c)
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm
RMFLAGS		=	-rf

FTPRINTF_DIR	=	./ft_printf
FTPRINTF_LIB	=	libftprintf.a
FTPRINTF		=	$(FTPRINTF_DIR)/$(FTPRINTF_LIB)

TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER		=	./ps_tester.pl

$(NAME): $(FTPRINTF) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FTPRINTF)

$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
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
	perl $(TESTER) 100 100

500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100

.PHONY: all clean fclean testclean re reb vis 3 5 100 500