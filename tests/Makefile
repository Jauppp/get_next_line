# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 19:16:12 by cdomet-d          #+#    #+#              #
#    Updated: 2023/12/07 17:26:48 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := gnl.exe

CC := gcc
CFLAGS := -Werror -Wextra -Wall 
CPPFLAGS := -fsanitize=address -fsanitize=leak -g
BUILD_DIR := .dir_build

SRCS := get_next_line_utils.c \
		get_next_line.c \
		gnl_test.c \
		
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o:%.c get_next_line.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(BUILD_DIR)
fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	$(all) @./$(NAME)
	
.PHONY : clean fclean all re

# $(CPPFLAGS)