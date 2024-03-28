# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:31:12 by jvasquez          #+#    #+#              #
#    Updated: 2022/08/10 15:42:10 by jvasquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FUNCTIONS =	pf_strlen.c			\
			pf_putchar_fd.c		\
			pf_putstr_fd.c		\
			pf_putnbr_fd.c		\
			ft_printf.c				\
			pf_putnbr_base.c		\

#DFUNCTIONS = $(addprefix $(DIR), ${FUNCTIONS})
OBJS = ${FUNCTIONS:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
			rm -f $(OBJS) 

fclean: clean
			rm -f $(NAME)

re: fclean all
