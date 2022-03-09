# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 09:22:13 by amarchan          #+#    #+#              #
#    Updated: 2022/03/07 14:25:30 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_putchar.c \
		utils/ft_putnbr.c \
		utils/ft_putstr.c \
		utils/ft_strcat.c \
		utils/ft_strlen.c \


OBJS1 := ${SRCS1:.c=.o}
OBJS2 := ${SRCS2:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

INC_DIR = headers

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -I ${INC_DIR} $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
		gcc -o $(NAME) $(OBJS)

clean:
	@${RM} ${OBJS1}

fclean: clean
	@${RM} ${NAME1}

re: fclean all

.PHONY: all clean fclean re