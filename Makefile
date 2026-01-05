NAME = so_long

SO_LONG_SOURCES = so_long.c setmap.c checkers/main_check.c checkers/checks1.c checkers/checks2.c\
checkers/checks_utils1.c gamelogic/game_man.c gamelogic/game_man_utils1.c gamelogic/game_man_utils2.c

GET_NEXT_LINE_SOURCES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SO_LONG_OBJECTS = $(SO_LONG_SOURCES:.c=.o)
GET_NEXT_LINE_OBJECTS = $(GET_NEXT_LINE_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror
LIBS += -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(SO_LONG_OBJECTS) $(GET_NEXT_LINE_OBJECTS) so_long.h
	cd ft_printf && make
	ar r so_long.a $(SO_LONG_OBJECTS) $(GET_NEXT_LINE_OBJECTS) so_long.h
	cc $(CFLAGS) so_long.a ft_printf/libftprintf.a minilibx-linux/libmlx_Linux.a -o so_long $(LIBS)

clean:
	rm -f $(SO_LONG_OBJECTS) get_next_line/$(GET_NEXT_LINE_OBJECTS)
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME) so_long.a
	cd ft_printf && make fclean

re: fclean all