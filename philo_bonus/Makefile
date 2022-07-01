# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 08:25:42 by gbreana           #+#    #+#              #
#    Updated: 2022/07/01 16:06:25 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

INCLM		=	include/philo_bonus.h

MDIR		= 	sources/

MFLS		=	main_bonus.c check_bonus.c utils1_bonus.c \
				utils2_bonus.c init_bonus.c routines_bonus.c \
				death_bonus.c free_bonus.c

MSRC		=	$(addprefix $(MDIR), $(MFLS))

MOBJS		=	$(patsubst %.c,%.o,$(MSRC))

MDEPS		=	$(patsubst %.c,%.d,$(MSRC))

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -MD -g #-fsanitize=thread
RM			=	rm -rf

override		OBJS_ALL ?= $(MOBJS)
override		DEP_ALL ?= $(DEPS)

$(MDIR)%.o:		$(MDIR)%.c Makefile include/philo.h
				$(CC) $(CFLAGS) -I $(INCLM) -c $< -o ${<:.c=.o}

all:			$(NAME)

$(NAME):		$(MOBJS)
				@$(CC) $(MOBJS) -o $@

clean:
				$(RM) $(MOBJS) $(MDEPS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re

#gcc -fsanitize=thread -g main.c check.c utils1.c utils2.c init.c routines.c death.c free.c -I ../include/philo.h -o philo