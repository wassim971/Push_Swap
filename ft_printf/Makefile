# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:18:41 by wbaali            #+#    #+#              #
#    Updated: 2024/11/26 13:22:18 by wbaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr_unsigned.c ft_putnbr.c ft_putstr.c ft_putpointer.c

SRCS = ${PRINTF}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar -rsc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean;
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re