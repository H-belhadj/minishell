NAME = libft.a 

SRC = ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_strlcat.c ft_strlcpy.c ft_atoi.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_tolower.c ft_toupper.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strlen.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c

OBJ =  ft_putnbr_fd.o  ft_putendl_fd.o ft_putchar_fd.o ft_putstr_fd.o ft_striteri.o ft_strmapi.o ft_itoa.o ft_split.o ft_strtrim.o ft_strjoin.o ft_substr.o ft_strdup.o ft_calloc.o ft_strlcat.o ft_strlcpy.o ft_atoi.o ft_strnstr.o ft_memcmp.o ft_memchr.o ft_strncmp.o ft_strrchr.o ft_strchr.o ft_tolower.o ft_toupper.o ft_memmove.o ft_memcpy.o ft_bzero.o ft_memset.o ft_strlen.o ft_isprint.o ft_isascii.o ft_isalnum.o ft_isdigit.o ft_isalpha.o

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -Wall -Werror -Wextra -c $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	