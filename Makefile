# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 09:22:13 by amarchan          #+#    #+#              #
#    Updated: 2022/04/07 17:45:09 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = bonus

NORMINETTE_BIN = norminette
NM_BIN = nm

SRCS =	src/ft_push_swap.c \
		src/ft_push_swap_utils.c \
		src/sortmore.c \
		src/sortmore_2.c \
		src/sortmore_utils.c \
		parsing/ft_parsing.c \
		parsing/ft_parsing_utils.c \
		moves/swap.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse_rotate.c \
		utils/ft_atoi.c \
		utils/ft_atoll.c \
		utils/ft_isdigit.c \
		utils/ft_isspace.c \
		utils/ft_lstrip.c \
		utils/ft_memcpy.c \
		utils/ft_memmove.c \
		utils/ft_putchar.c \
		utils/ft_putnbr.c \
		utils/ft_putstr.c \
		utils/ft_rstrip.c \
		utils/ft_strcat.c \
		utils/ft_strlen.c \
		utils/ft_lstadd_back.c \
		utils/ft_lstadd_front.c \
		utils/ft_lstclear_back.c \
		utils/ft_lstclear_first.c \
		utils/ft_lstclear.c \
		utils/ft_lstnew.c \
		utils/ft_lstsize.c \
		utils/ft_lstcopy.c \

SRCS_B =	pushswap_bonus/checker.c \
			pushswap_bonus/checker_utils.c \
			pushswap_bonus/get_next_line.c \
			pushswap_bonus/get_next_line_utils.c \
			pushswap_bonus/bonus_swap.c \
			pushswap_bonus/bonus_push.c \
			pushswap_bonus/bonus_rotate.c \
			pushswap_bonus/bonus_reverse_rotate.c \
			src/ft_push_swap_utils.c \
			src/sortmore.c \
			src/sortmore_2.c \
			src/sortmore_utils.c \
			parsing/ft_parsing.c \
			parsing/ft_parsing_utils.c \
			utils/ft_atoi.c \
			utils/ft_atoll.c \
			utils/ft_isdigit.c \
			utils/ft_isspace.c \
			utils/ft_lstrip.c \
			utils/ft_memcpy.c \
			utils/ft_memmove.c \
			utils/ft_putchar.c \
			utils/ft_putnbr.c \
			utils/ft_putstr.c \
			utils/ft_rstrip.c \
			utils/ft_strcat.c \
			utils/ft_strlen.c \
			utils/ft_strcmp.c \
			utils/ft_lstadd_back.c \
			utils/ft_lstadd_front.c \
			utils/ft_lstclear_back.c \
			utils/ft_lstclear_first.c \
			utils/ft_lstclear.c \
			utils/ft_lstnew.c \
			utils/ft_lstsize.c \
			utils/ft_lstcopy.c \

OBJS := ${SRCS:.c=.o}

OBJS_B := ${SRCS_B:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -rf

INC_DIR = headers

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -I ${INC_DIR} $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		gcc -o $(NAME) $(OBJS)

$(BONUS): ${OBJS_B}
		gcc -o checker $(OBJS_B)

all: $(NAME)

clean:
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@${RM} ${NAME} ${BONUS}

re: fclean all

norme:
	@${NORMINETTE_BIN} ${SRCS} ${SRCS_B}

sym:
	@${NM_BIN} -Dgu $(NAME) checker

.PHONY: all clean fclean re norme sym