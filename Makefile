NAME = fillit
SRCS_DIR = ./
INCLUDE = ./
RM = /bin/rm -f

FILES = main setdlc defpcs errorcheck

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OFILES):
	gcc $(CFLAGS) -c -I$(INCLUDE) $(CFILES)

$(NAME): $(OFILES)
	gcc $(CFLAGS) -o $(NAME) $(OFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all