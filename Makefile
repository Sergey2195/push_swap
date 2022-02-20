# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iannmari <iannmari@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:27:24 by iannmari          #+#    #+#              #
#    Updated: 2022/02/16 14:10:12 by iannmari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PS	= 	mandatory/action.c mandatory/action2.c mandatory/action3.c mandatory/calc_flags.c mandatory/err.c mandatory/ft_atoi.c mandatory/last_rotate.c mandatory/main.c mandatory/min_flag.c mandatory/mini_s.c mandatory/sorting.c mandatory/stack_utils.c mandatory/utils.c mandatory/m_utils.c

SRCS_CH	=	bonus/act_b.c bonus/act2_b.c bonus/act3_b.c bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c mandatory/action.c  mandatory/m_utils.c mandatory/action2.c mandatory/action3.c mandatory/calc_flags.c mandatory/err.c mandatory/ft_atoi.c mandatory/last_rotate.c mandatory/min_flag.c mandatory/mini_s.c mandatory/sorting.c mandatory/stack_utils.c mandatory/utils.c

HEADER_PS	=	mandatory/push_swap.h bonus/checker.h

OBJS_PS	=	$(SRCS_PS:.c=.o)

OBJS_CH	=	$(SRCS_CH:.c=.o)

NAME_PS	=	push_swap

NAME_CH	=	checker

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Werror -Wextra

$(NAME_PS)	:		$(OBJS_PS) $(HEADER_PS)
	$(CC) -o $(NAME_PS) $(OBJS_PS)

$(NAME_CH)	:		$(OBJS_CH) $(HEADER_PS)
	$(CC) -o $(NAME_CH) $(OBJS_CH)

all			:	$(NAME_PS) $(NAME_CH)

%.o			:	%.c $(HEADER_PS)
	$(CC) $(FLAGS) -c $< -o $@

clean		:
	@$(RM)	$(OBJS_PS) $(OBJS_CH)

fclean		:	clean
	@$(RM) push_swap checker

re:	fclean all

.PHONY: all clean fclean re