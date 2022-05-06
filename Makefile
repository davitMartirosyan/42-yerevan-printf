# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 20:17:25 by dmartiro          #+#    #+#              #
#    Updated: 2022/05/06 18:23:57 by dmartiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= printf
CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror
OBJS		= lib/__base__16.o \
			  lib/__number__.o \
			  lib/__pointer__.o \
			  lib/spat.o \
			  lib/utils.o \
			  ft_printf.o

all: printf

printf: $(OBJS)
	$(CC) $(CC_FLAGS) -o printf $(OBJS)

lib/__base__16.o : lib/__base__16.c ft_printf.h
	$(CC) $(CC_FLAGS) -c lib/__base__16.c

lib/__number__.o : lib/__number__.c ft_printf.h
	$(CC) $(CC_FLAGS) -c lib/__base__16.c

lib/__pointer__.o : lib/__pointer__.c ft_printf.h
	$(CC) $(CC_FLAGS) -c lib/__pointer__.c

lib/spat.o : lib/spat.c ft_printf.h
	$(CC) $(CC_FLAGS) -c lib/spat.c

lib/utils.o : lib/spat.c ft_printf.h
	$(CC) $(CC_FLAGS) -c lib/utils.c

ft_printf.o : ft_printf.c ft_printf.h
	$(CC) $(CC_FLAGS) -c ft_printf.c