# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 14:49:09 by wbaali            #+#    #+#              #
#    Updated: 2025/02/06 15:19:49 by wbaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMMANDE = $(addprefix commande/, push.c r_rotate.c rotate.c sort_commande_two.c sort_commande.c swap.c)

SRC =  $(addprefix srcs/, checkerror.c find.c ft_splits.c init_nodes_b.c init_nodes.c init_pile.c main.c pile_utile.c push_swap_utils.c)

SRCS = ${COMMANDE} ${SRC}

OBJS = ${SRCS:.c=.o}

INCLUDE = -Iinclude

CC = cc -g3

CFLAGS = -Wall -Werror -Wextra

LIBFTPATH = libft

LIBFT = $(LIBFTPATH)/libft.a

FT_PRINTF_PATH = ft_printf

FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o} 

$(NAME) : $(OBJS) $(LIBFT) $(FT_PRINTF)
	${CC} ${CFLAGS}${INCLUDE} $^ -o $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFTPATH)

$(FT_PRINTF) : 
	$(MAKE) -C $(FT_PRINTF_PATH)

all: ${NAME}

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C $(FT_PRINTF_PATH)
	$(MAKE) clean -C $(LIBFTPATH)

fclean: clean
	rm -f ${NAME}
	$(MAKE) fclean -C $(FT_PRINTF_PATH)
	$(MAKE) fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re