# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:17:35 by ezanotti          #+#    #+#              #
#    Updated: 2023/05/10 16:43:00 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname -s)

ifeq ($(OS), Linux)
	PRINT	= @printf
endif
ifeq ($(OS), Darwin)
	PRINT	= @printf
endif

S_LIST		= main.c \
			${D_EXEC}ft_born.c \
			${D_EXEC}ft_launch_philos.c \
			${D_EXEC}ft_start_execution.c \
			${D_EXEC}ft_wait_death.c \
			${D_EXEC}ft_wait_threads.c \
			${D_PARSE}ft_argv_checker.c	\
			${D_TIME}ft_diff.c \
			${D_TIME}ft_get_time.c \
			${D_TIME}ft_usleep.c \
			${D_UTILS}ft_atoi.c \
			${D_UTILS}ft_error.c \
			${D_UTILS}ft_free_all.c \
			${D_UTILS}ft_init_all.c \
			${D_UTILS}ft_is_dead.c \
			${D_UTILS}ft_print_info.c \

S_PHILO		= ${addprefix ${DIR_SRC}, ${S_LIST}}
OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(S_PHILO))

# DIRECTORIES
DIR_OBJS	= .objs/
DIR_INCLUDE = includes/
DIR_SRC		= srcs/
D_EXEC		= exec/
D_PARSE		= parsing/
D_TIME		= time/
D_UTILS		= utils/

# VARIABLES
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
MAKEFLAGS	+= --no-print-directory

# COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
DEFAULT		= \033[0m
SUPPR		= \r\033[2K

# COMPILATION
all :		${NAME}

${DIR_OBJS}%.o: %.c	${DIR_INCLUDE}philo.h Makefile
			@mkdir -p $(shell dirname $@)
			@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
			@${CC} ${CFLAGS} -I ${DIR_INCLUDE} -c $< -o $@

${NAME}:	ascii ${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
			@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
			@${CC} ${OBJS} -o ${NAME} -pthread
			@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

ascii :
			@${PRINT} "$$ASCII"

clean :		ascii
			@${PRINT} "${RED}Deleting objects : DONE\n"
			@${RM} ${DIR_OBJS}

fclean :	clean
			@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n\n"
			@${RM} ${NAME}

re :		fclean all

define ASCII
${CYAN} _____ _____ _____ __    _____ _____ _____ _____ _____ _____ _____ _____ 
|  _  |  |  |     |  |  |     |   __|     |  _  |  |  |   __| __  |   __|
|   __|     |-   -|  |__|  |  |__   |  |  |   __|     |   __|    -|__   |
|__|  |__|__|_____|_____|_____|_____|_____|__|  |__|__|_____|__|__|_____|

${DEFAULT}
endef

export ASCII

.PHONY :	all re clean fclean ascii
