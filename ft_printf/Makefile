NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./arg_functions/print_hex.c ./arg_functions/print_ptr_hex.c ./arg_functions/print_int.c ./arg_functions/print_uint.c ./arg_functions/print_str.c \
			ft_printf.c

OBJ = $(SRC:.c=.o)

LIBFTSRC = ./libft/ft_isalpha.c ./libft/ft_putnbr_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putstr_fd.c \
./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_split.c ./libft/ft_strmapi.c ./libft/ft_strtrim.c \
./libft/ft_itoa.c ./libft/ft_strjoin.c ./libft/ft_substr.c ./libft/ft_strdup.c ./libft/ft_calloc.c ./libft/ft_atoi.c \
./libft/ft_strnstr.c ./libft/ft_isdigit.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strncmp.c ./libft/ft_strrchr.c \
./libft/ft_isalnum.c ./libft/ft_strchr.c ./libft/ft_isascii.c ./libft/ft_isprint.c ./libft/ft_strlen.c ./libft/ft_tolower.c \
./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c ./libft/ft_toupper.c
LIBFTOBJ = $(LIBFTSRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)

clean:
	make clean -C ./libft/
	rm -f *.o ./arg_functions/*.o

fclean: clean
	make fclean -C ./libft/
	rm -f *.a

re: fclean all
	make re -C ./libft/