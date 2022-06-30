# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 08:25:42 by gbreana           #+#    #+#              #
#    Updated: 2022/06/30 14:22:08 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

INCLM		=	./include/philo.h

MDIR		= 	./sources/

MFLS		=	main.c check.c utils1.c utils2.c init.c routines.c death.c free.c

MSRC		=	$(addprefix $(MDIR), $(MFLS))

MOBJS		=	$(patsubst %.c,%.o,$(MSRC))

MDEPS		=	$(patsubst %.c,%.d,$(MSRC))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD #-fsanitize=thread -g
RM			=	rm -rf

override		OBJS_ALL ?= $(MOBJS)
override		DEP_ALL ?= $(DEPS)

$(MDIR)%.o:		$(MDIR)%.c Makefile include/philo.h
				$(CC) $(CFLAGS) -Imlx -I $(INCLM) -c $< -o ${<:.c=.o}

all:			$(LIBFT) $(MLXLIB) $(NAME)

$(NAME):		$(MOBJS)
				@$(CC) $(MOBJS) -o $@

clean:
				$(RM) $(MOBJS) $(MDEPS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re