# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:00:25 by fporciel          #+#    #+#              #
#    Updated: 2023/09/09 12:41:33 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# This is a personal, generic implementation of the standard C function
# 'printf', made for the sole purpose of learning the mechanics of this classic
# C programming tool. The result does not conform, at the time of production, 
# to any standard. Compared to the standard function, some features are missing.
# In some cases, attempts have been made to resolve behaviors that are undefined
# in the standard.
# `printf` stands for "Print Formatted Information". It is a standard library
# function in C and other programming languages that allows you to format and 
# print data to the screen or a file in a structured format.  
# Copyright (C) 2023  fporciel
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# You can contact the author at: 
#- fporciel@student.42roma.it
#

.PHONY: all clean fclean re bonus download_libft
.DEFAULT_GOAL := $(NAME)
NAME := libftprintf.a
FT_PRINTF_DIR := $(shell pwd)
FT_DIR := $(FT_PRINTF_DIR)/1_libft
FT_LIB := $(FT_LIB)/libft.a
HEADERS_DIRS := $(FT_PRINTF_DIR) $(FT_DIR)
HEADERS := $(filter-out %bonus.h, $(wildcard ft_*.h))
BONUS_HEADERS := $(wildcard ft_*bonus.h)
SOURCE_FILES := $(filter-out %bonus.c, $(wildcard ft_*.c))
BONUS_SOURCE_FILES := $(wildcard ft_*bonus.c)
OBJECT_FILES := $(patsubst %c, %.o, $(SOURCE_FILES))
BONUS_OBJECT_FILES := $(patsubst %.c, %.o, $(BONUS_SOURCE_FILES))
CC := gcc
INCLUDE := $(addprefix -I, $(HEADERS_DIRS))
COMPILER_FLAGS := -Wall -Wextra -Werror -O1 -Os -g -fsanitize=address \
	$(INCLUDE) -c

$(NAME): $(FT_LIB) $(OBJECT_FILES)
	ar rcs $(NAME) $(FT_LIB) $(OBJECT_FILES)
	make clean

all: $(NAME)

bonus: $(NAME) $(BONUS_OBJECT_FILES)
	ar rcs $(NAME) $(BONUS_OBJECT_FILES)
	make clean

$(OBJECT_FILES): $(SOURCE_FILES) $(HEADERS)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_FILES) $(HEADERS)
	rm -f $(HEADERS).gch

$(BONUS_OBJECT_FILES): $(BONUS_SOURCE_FILES) $(BONUS_HEADERS)
	$(CC) $(COMPILER_FLAGS) $(BONUS_SOURCE_FILES) $(BONUS_HEADERS)
	rm -f $(BONUS_HEADERS).gch

$(FT_LIB): $(FT_DIR)
	cd $(FT_DIR) && make bonus && cd ..

$(FT_DIR):
	if [ ! -e $(FT_DIR) ]; \
		then if [ -e ../1_libft ]; \
		then ln -s ../1_libft $(FT_DIR); \
		else make download_libft; fi; fi

download_libft:
	git clone git@github.com:fporciel2/1_libft.git

clean:
	rm -f *.o
	cd $(FT_DIR) && make clean && cd ..

fclean: clean
	rm -f *.a
	cd $(FT_DIR) && make fclean && cd ..

re: clean fclean

