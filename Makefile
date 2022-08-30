# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jklein <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 13:14:46 by jklein            #+#    #+#              #
#    Updated: 2022/01/27 15:51:50 by jklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
SRCS = ft_printf.c ft_putchar_len.c ft_nbr.c ft_str.c ft_uxxp.c
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
