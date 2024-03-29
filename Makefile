# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 15:43:28 by lpersin           #+#    #+#              #
#    Updated: 2019/08/28 16:00:44 by lpersin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -g
LDFLAGS = -L./libft -lft

SRCDIR = src
OBJDIR = obj
#BINDIR = bin
LIBDIR = libft

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = minishell

LIB = libft.a
.PHONY:  all clean fclean re $(LIBDIR)

all: $(LIBDIR) $(NAME) 

$(NAME): $(OBJECTS) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR) :
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) clean -C  $(LIBDIR)
	/bin/rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C  $(LIBDIR)
	/bin/rm -rf $(NAME)

re: fclean all
