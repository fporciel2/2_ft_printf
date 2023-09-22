# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 11:52:34 by fporciel          #+#    #+#              #
#    Updated: 2023/09/22 11:52:38 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

OBJS := ft_printf.o handle_c.o handle_str.o handle_decimal.o handle_void.o handle_hexlower.o handle_hexupper.o handle_unsdec10.o

FLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) ${B_OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all
