NAME = philo

SRC_DIR = ./
SRC = \
	main.c console.c utils.c inc/mini_libft/ft_calloc.c inc/mini_libft/ft_itoa.c \
	inc/mini_libft/ft_strdup.c init.c
SOURCES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -pthread

G			= \033[0;90m #gray
R			= \033[0;91m #red
GR			= \033[0;92m #green
Y			= \033[0;93m #yellow
B			= \033[0;94m #blue
M			= \033[0;95m #magenta
C			= \033[0;96m #cyan
W			= \033[0;97m #white
ENDCOLOR	= \033[0m #reset
BG_G		= \033[42m #bg_g

all: $(NAME) print

print:
	@echo "${GR}"
	@echo "${GR}.------.${C}.------.${B}.------.${M}.------.${Y}.------.${R}"
	@echo "${GR}|P.--. |${C}|H.--. |${B}|I.--. |${M}|L.--. |${Y}|O.--. |${R}"
	@echo "${GR}| :/\: |${C}| :/\: |${B}| (\/) |${M}| :/\: |${Y}| :/\: |${R}"
	@echo "${GR}| (__) |${C}| (__) |${B}| :\/: |${M}| (__) |${Y}| :\/: |${R}"
	@echo "${GR}| '--'P|${C}| '--'H|${B}| '--'I|${M}| '--'L|${Y}| '--'O|${R}"
	@echo "${GR}\______/${C}\______/${B}\______/${M}\______/${Y}\______/${R}"
	@echo " "
	@echo " "
	@echo "${ENDCOLOR}"

$(NAME): $(OBJS)
	@echo "${GR}"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	@echo "${C}"
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo fclean: OK

re: fclean all