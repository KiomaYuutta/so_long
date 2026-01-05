NAME = libftprintf.a

SOURCES = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) ft_printf.h
	cd libft && make re && mv libft.a ../
	mv libft.a $(NAME)
	ar r $(NAME) $(OBJECTS) ft_printf.h

clean:
	rm -f $(OBJECTS)
	cd libft && make clean

fclean: clean
	rm -f libftprintf.a
	cd libft && make fclean

re: fclean all