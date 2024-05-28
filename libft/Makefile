# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 09:51:05 by fmontes           #+#    #+#              #
#    Updated: 2023/10/27 14:58:38 by fmontes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
            ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
            ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
            ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
            ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
            ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	    ft_strmapi.c ft_striteri.c	ft_strtrim.c ft_putnbr_fd.c \
	    ft_itoa.c ft_split.c	
	    
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
