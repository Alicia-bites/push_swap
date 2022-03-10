# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 09:22:13 by amarchan          #+#    #+#              #
#    Updated: 2022/03/10 12:21:03 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	src/ft_push_swap.c \
		parsing/ft_parsing.c \
		parsing/ft_panic.c \
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
		utils/ft_lstclear_back.c \
		utils/ft_lstclear.c \
		utils/ft_lstnew.c \
		utils/ft_lstsize.c \

OBJS := ${SRCS:.c=.o}

CC = clang

CFLAGS = -g3 -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

INC_DIR = headers

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -I ${INC_DIR} $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
		gcc -o $(NAME) $(OBJS)

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re