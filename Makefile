NAME	= my_hunter

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./lib/*.c \
	  ./init_teemo.c \
	  ./engine.c \
	  ./victory.c \
	  ./len_nbr.c \
	  ./to_base.c \
	  ./shop.c \
	  ./misc.c \
	  ./game_over.c \
	  ./init_engine.c \
	  ./title_screen.c

CFLAGS = -I ./lib/my/
CFLAGS += -Wall -Wextra

all:
	 $(CC) $(SRCS) -o $(NAME) -lc_graph_prog -g3

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
