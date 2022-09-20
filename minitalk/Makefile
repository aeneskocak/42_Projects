NAME = minitalk
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER = server
SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

CLIENT = client
SRCCLIENT = client.c
OBJCLIENT = $(SRCCLIENT:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): lib $(SERVER) $(CLIENT)

$(SERVER): $(OBJSERVER)
	$(CC) $(CFLAGS) $(OBJSERVER) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJCLIENT)
	$(CC) $(CFLAGS) $(OBJCLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)

lib:
	cd libft && make
	cd ft_printf && make

clean:
	cd libft && make clean
	cd ft_printf && make clean
	$(RM) $(OBJSERVER) $(OBJCLIENT)

fclean:
	cd libft && make fclean
	cd ft_printf && make fclean
	$(RM) $(SERVER) $(CLIENT) $(OBJSERVER) $(OBJCLIENT)

re: fclean all

.PHONY: all clean re lib
