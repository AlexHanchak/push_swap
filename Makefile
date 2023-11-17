# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 15:44:28 by ohanchak          #+#    #+#              #
#    Updated: 2023/10/05 16:48:30 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs/

DIR_OBJS	=	./compiled_srcs/

SRC			=	push_swap.c \
				init_stacks.c \
				stacks.c \
				align_stacks.c \
				operations.c \
				check_req.c \
				movements.c \
				states.c \
				resolution.c \
				bruteforce.c \
				b_operations.c \
				utils.c \
				cleaner.c \
				print.c \
				debug.c

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME 		=	push_swap


all:			$(NAME)


$(NAME):		$(OBJS)
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)


$(OBJS):		| $(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)


clean:
				@$(RM) $(DIR_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re norm
