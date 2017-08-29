NAME = exe
NAMELIB = libtest.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = test.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

SRCLIB = abs.c  slicereverse.c  tolower.c
OBJLIB = $(addprefix $(OBJLIBDIR), $(SRCLIB:.c=.o))

LIBDIR = lib/
SRCDIR = src/
INCDIR = includes/
OBJDIR = obj/
OBJLIBDIR = objlib/

all: obj $(NAMELIB) $(NAME)

obj:    
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJLIBDIR)

$(OBJLIBDIR)%.o: $(LIBDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMELIB): $(OBJLIB)
	ar rc $(NAMELIB) $(OBJLIB)
	ranlib $(NAMELIB)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC)  $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L. $(NAMELIB)

clean:
	$(RM) $(OBJDIR)
	$(RM) $(OBJLIBDIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMELIB)

re: fclean all