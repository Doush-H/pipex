NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
ft_striteri.c ft_putchar_fd.c ft_split.c ft_strmapi.c ft_strtrim.c \
ft_itoa.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_atoi.c \
ft_strnstr.c ft_isdigit.c ft_memchr.c ft_memcmp.c ft_strncmp.c ft_strrchr.c \
ft_isalnum.c ft_strchr.c ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c
OBJ = $(SRC:.c=.o)
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstmap.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
BOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:	$(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re
