# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 16:58:21 by jchevet           #+#    #+#              #
#    Updated: 2020/12/17 16:58:46 by jchevet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBDIR	=	libft/
LIBFT	=	libft.a
SRCSF	=	ft_printf.c ft_flags.c ft_get_prec_width.c ft_put_field_and_prec.c ft_print_c_str.c ft_print_int.c\
			ft_print_p_u_x.c
SRCDIR	=	srcs/
INDIR	=	includes/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(SRCDIR),$(SRCSF))
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

.c.o	:
			$(CC) $(CFLAGS) -I$(LIBDIR) -I$(INDIR) -c $< -o $(<:.c=.o)

bonus	:	all

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C $(LIBDIR)
			cp $(LIBDIR)$(LIBFT) $(NAME)
			ar -vrs $(NAME) $(OBJS)

libft	:
			make -C $(LIBDIR)
			cp $(LIBDIR)$(LIBFT) $(LIBFT)

clean	:
			make clean -C $(LIBDIR)
			rm -f $(OBJS) $(OBJS_B) $(LIBFT)

fclean	:	clean
			make fclean -C $(LIBDIR)
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	re clean fclean libft
