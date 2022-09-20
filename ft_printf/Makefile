NAME = libftprintf.a
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
RM = rm -rf

SRCS = ft_printf.c \
			ft_printfutils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
