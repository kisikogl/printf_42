.PHONY : all clean fclean re

NAME = libftprintf.a
SRCS := ft_printf.c ft_putstuff.c ft_putmorestuff.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -sC libft/
	ar -rc $(NAME) $(OBJECTS) libft/*.o

$(OBJECTS): $(SRCS)
	cc -c $^ -Wall -Wextra -Werror

clean:
	@make clean -C libft/
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
