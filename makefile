# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 16:45:18 by alganoun     #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 17:18:13 by alganoun    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= libftprintf.a

HEAD	= ./includes/libft_printf.h

SRCS	=	./srcs/ft_printf.c \
			./srcs/conversions/ft_printf_conversions.c \
			./srcs/conversions/ft_printf_conversions2.c \
			./srcs/Parsing_typeselection/ft_printf_parsing.c \
			./srcs/Parsing_typeselection/ft_printf_typeselection.c \
			./srcs/utils/ft_printf_utils.c \
			./srcs/utils/conversion_utils/ft_printf_digitnbs.c \
			./srcs/utils/conversion_utils/ft_printf_processes.c \
			./srcs/utils/conversion_utils/ft_printf_putnbrs.c \

OBJS	= ${SRCS:.c=.o}

CC 		= gcc -Wall -Wextra -Werror

RM		= rm -f

all: ${NAME}

$(OBJS) : ${HEAD}

$(OBJBNUS) : ${OBJ} ${HEAD}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
