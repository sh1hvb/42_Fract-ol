NAME = fractol


SRCS = fractol.c init.c julia.c utils.c events.c 


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 


RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS}  ${OBJS}  ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS}  -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	${MAKE} -C ./libft fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

