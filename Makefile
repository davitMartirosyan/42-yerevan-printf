ARCHIVE=libftprintf.a
SRC_FOLDER=src
SRC=$(wildcard $(SRC_FOLDER)/*.c)
OBJ=$(SRC:.c=.o)
CC=gcc
CC_FL=-Wall -Wextra -Werror
all: $(ARCHIVE)

$(ARCHIVE) : $(OBJ)
	@ar r $(ARCHIVE) $(OBJ)

$(SRC_FOLDER)%.c : $(SRC)
	@$(CC) $(CC_FL) $< -c $@
	@echo compiling $<

clean :
	rm -f $(SRC_FOLDER)/*.o

fclean : clean
	rm -f libftprintf.a

re : fclean all

.PHONY: clean all re fclean