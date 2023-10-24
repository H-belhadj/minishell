# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 18:24:14 by omakran           #+#    #+#              #
#    Updated: 2023/10/24 19:11:51 by hbelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCE = minishell.c tokens.c sort_cmds.c  cmp.c errors.c expand.c remove_quotes.c execut.c exit.c ft_echo.c pwd.c env.c cd.c env_export.c ft_getenv.c export.c unset.c path.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

READLINE = -lreadline

OBJS = $(SOURCE:.c=.o)

RM = rm -rf

all: $(NAME)

LIBFT=libft_/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(READLINE) $(LIBFT)
	@mkdir obj
	mv *.o obj/

clean:
	$(RM) $(OBJS)
	@rm -rf obj/ 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

