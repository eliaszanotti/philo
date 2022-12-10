# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 11:24:38 by ezanotti          #+#    #+#              #
#    Updated: 2022/12/10 11:26:46 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_PHILO	= ${DIR_SRC}main.c

OBJS	= ${S_PHILO:.c=.o}

# VARIABLES
NAME	= philo
DIR_SRC = srcs/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR_SRC}philo.h Makefile
			${CC} ${CFLAGS} -I ${DIR_SRC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
