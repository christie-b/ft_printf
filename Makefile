# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#              #
#    Updated: 2021/06/12 11:50:44 by cboutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR	= .

SRCS	= ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_flags.c ft_printf_p.c ft_printf_pct.c ft_printf_s.c ft_printf_u.c \
			ft_printf_utils.c ft_printf_x.c


OBJS	= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar -rcs

RM			= rm -f

RL			= ranlib

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

all:		${NAME}

bonus:		${OBJS}
			${AR} ${NAME} ${OBJS}
			${RL} ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean