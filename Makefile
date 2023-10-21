CC = cc
CFLAGS = -Wall -Wextra -Werror  
NAME = push_swap
SOURCES = cd.c echo.c env.c exit.c export.c  pwd.c unset.c
OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[1;32mDONE!\033[0m"

OBJTS: $(SOURCES)
	$(CC) $(CFLAGS) -c $^

clean : 
	@echo "\033[36mCleaning push_swap....\033[0m"
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all