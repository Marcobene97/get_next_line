# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 20:49:56 by mbenedet          #+#    #+#              #
#    Updated: 2025/11/19 17:55:30 by mbenedet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = get_next_line.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re