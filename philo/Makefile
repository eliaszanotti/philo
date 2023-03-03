# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 11:24:38 by ezanotti          #+#    #+#              #
#    Updated: 2023/03/03 14:02:25 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_PHILO	= ${DIR_SRC}main.c ${DIR_SRC}ft_atoi.c ${DIR_SRC}ft_struct_init.c \
		${DIR_SRC}ft_log.c ${DIR_SRC}ft_launch_philos.c \
		${DIR_SRC}ft_time_utils.c ${DIR_SRC}ft_waits.c

OBJS	= ${S_PHILO:.c=.o}

# VARIABLES
NAME	= philo
DIR_SRC = srcs/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR_SRC}philo.h Makefile
			${CC} ${CFLAGS} -pthread -I ${DIR_SRC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} ${OBJS} -pthread -o ${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
