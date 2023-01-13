NAME = pipex
BONUS_NAME = pipex
CC = cc
CFLAGS = -Werror -Wextra -Wall
RM = rm -rf

SRC = main.c utils.c cmd_utils.c
OBJ = $(SRC:.c=.o)

BONSRC = bonus/main_bonus.c bonus/cmd_utils_bonus.c bonus/pipe_utils_bonus.c bonus/utils_bonus.c
BONOBJ = $(BONSRC:.c=.o)

GNLSRC = ./GNL/get_next_line.c ./GNL/get_next_line_utils.c
GNLOBJ = $(GNLSRC:.c=.o)

PRINTFSRC = ./ft_printf/arg_functions/print_hex.c ./ft_printf/arg_functions/print_ptr_hex.c ./ft_printf/arg_functions/print_int.c ./ft_printf/arg_functions/print_uint.c ./ft_printf/arg_functions/print_str.c \
			./ft_printf/ft_printf.c
PRINTFOBJ = $(PRINTFSRC:.c=.o)

LIBFTSRC = ./ft_printf/libft/ft_isalpha.c ./ft_printf/libft/ft_putnbr_fd.c ./ft_printf/libft/ft_putendl_fd.c ./ft_printf/libft/ft_putstr_fd.c \
./ft_printf/libft/ft_striteri.c ./ft_printf/libft/ft_putchar_fd.c ./ft_printf/libft/ft_split.c ./ft_printf/libft/ft_strmapi.c ./ft_printf/libft/ft_strtrim.c \
./ft_printf/libft/ft_itoa.c ./ft_printf/libft/ft_strjoin.c ./ft_printf/libft/ft_substr.c ./ft_printf/libft/ft_strdup.c ./ft_printf/libft/ft_calloc.c ./ft_printf/libft/ft_atoi.c \
./ft_printf/libft/ft_strnstr.c ./ft_printf/libft/ft_isdigit.c ./ft_printf/libft/ft_memchr.c ./ft_printf/libft/ft_memcmp.c ./ft_printf/libft/ft_strncmp.c ./ft_printf/libft/ft_strrchr.c \
./ft_printf/libft/ft_isalnum.c ./ft_printf/libft/ft_strchr.c ./ft_printf/libft/ft_isascii.c ./ft_printf/libft/ft_isprint.c ./ft_printf/libft/ft_strlen.c ./ft_printf/libft/ft_tolower.c \
./ft_printf/libft/ft_memset.c ./ft_printf/libft/ft_bzero.c ./ft_printf/libft/ft_memcpy.c ./ft_printf/libft/ft_memmove.c ./ft_printf/libft/ft_strlcpy.c ./ft_printf/libft/ft_strlcat.c ./ft_printf/libft/ft_toupper.c
LIBFTOBJ = $(LIBFTSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(GNLOBJ) $(LIBFTSRC) $(PRINTFSRC)
	make -C ./ft_printf
	$(CC) $(OBJ) $(GNLOBJ) $(LIBFTOBJ) $(PRINTFOBJ) -o $(NAME)

clean:
	make clean -C ./ft_printf
	$(RM) $(OBJ) $(BONOBJ) $(GNLOBJ)

fclean: clean
	make fclean -C ./ft_printf
	$(RM) $(NAME) $(BONUS_NAME)

bonus: $(BONOBJ) $(GNLOBJ) $(LIBFTSRC) $(PRINTFSRC)
	make -C ./ft_printf	
	$(CC) $(BONOBJ) $(GNLOBJ) $(LIBFTOBJ) $(PRINTFOBJ) -o $(BONUS_NAME)

re: fclean all