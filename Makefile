# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:03:14 by ohanchak          #+#    #+#              #
#    Updated: 2023/04/29 17:49:29 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

RM = /bin/rm -f

SRCS = push_swap.c /
		push_swap.h /
		ft_push.c /
		ft_swap.c /
		ft_rotate.c /
		ft_reverse_rotate.c /
		ft_putstr.c /
		ft_strlen.c /
		
OBJS = $(SRCS:%.c=$/%.o)

all:
	$(SRCS)

clean:
	$(RM) -r $(OBJS)
