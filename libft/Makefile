# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:31:12 by jvasquez          #+#    #+#              #
#    Updated: 2024/03/28 19:58:00 by jvasquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = .
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)
DIR_RGX = ./regex/
DIR_LST = ./lst/
DIR_MEM = ./mem/
DIR_PUT = ./put/
DIR_CHECK= ./check/
DIR_TO = ./to/
DIR_STR = ./str/
DIR_PF = ./printf/
DIR_GNL = ./gnl/
DIR_ARR = ./arr/
DIR_TREE = ./tree/

GNL =		get_next_line.c		\
			get_next_line_utils.c

PF =		ft_printf.c			\
			pf_putnbr_fd.c		\
			pf_putstr_fd.c		\
			pf_strlen.c			\
			pf_putchar_fd.c		\
			pf_putnbr_base.c

PUT =		ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c 	\
			ft_putnbr_fd.c

TO = 		ft_atoi.c			\
			ft_itoa.c 			\
			ft_atoi_pos.c		\
			ft_atoi_btwn.c		\
			ft_atod.c

MEM = 		ft_bzero.c			\
			ft_calloc.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			 

STR =		ft_strlen.c			\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strncmp.c		\
		   	ft_strnstr.c		\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strjoinfree.c	\
			ft_split.c			\
			ft_unsplit.c		\
			ft_strtrim.c		\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_strlcpy.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_substr.c			\
			ft_strbrk.c			\
			ft_strrep.c			\
			ft_strfree.c		\
			ft_chr_count.c		\
			ft_strstr.c			\
			ft_strrep.c			\
			ft_chrpos.c			\
			ft_strget_btwn.c

CHECK =		ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_isspace.c

LST =		ft_lstnew_bonus.c		\
			ft_lstadd_front_bonus.c	\
			ft_lstadd_back_bonus.c	\
			ft_lstlast_bonus.c		\
			ft_lstsize_bonus.c		\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c

ARR =		ft_sarrcpy.c	\
			ft_sarrsize.c	\
			ft_sarradd.c	\
			ft_sarrfree.c	\
			ft_sarrrmi.c	\
			ft_sarrprint.c	\
			ft_sarrcmp.c	\
			ft_sarrrep.c

TREE =		tree_in_order.c		\
			tree_pre_order.c	\
			tree_new_node.c		\
			tree_del_node.c		\
			tree_post_order.c

OBJS = $(addprefix $(DIR_LST), ${LST:.c=.o})
OBJS += $(addprefix $(DIR_RGX), ${RGX:.c=.o})
OBJS += $(addprefix $(DIR_MEM), ${MEM:.c=.o})
OBJS += $(addprefix $(DIR_PUT), ${PUT:.c=.o})
OBJS += $(addprefix $(DIR_CHECK), ${CHECK:.c=.o})
OBJS += $(addprefix $(DIR_TO), ${TO:.c=.o})
OBJS += $(addprefix $(DIR_STR), ${STR:.c=.o})
OBJS += $(addprefix $(DIR_PF), ${PF:.c=.o})
OBJS += $(addprefix $(DIR_GNL), ${GNL:.c=.o})
OBJS += $(addprefix $(DIR_ARR), ${ARR:.c=.o})
OBJS += $(addprefix $(DIR_TREE), ${TREE:.c=.o})

#	pwd
#	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all
