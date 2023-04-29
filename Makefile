# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:03:14 by ohanchak          #+#    #+#              #
#    Updated: 2023/04/29 17:34:14 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

RM = /bin/rm -f

SRCS = push_swap.c /
		push_swap.h /
		ft_push.c
		
OBJS = $(SRCS:%.c=$/%.o)

all:
	$(SRCS)

clean:
	$(RM) -r $(OBJS)
