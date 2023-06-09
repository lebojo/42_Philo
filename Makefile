# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordan <jordan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 01:10:08 by jordan            #+#    #+#              #
#    Updated: 2023/06/07 06:42:08 by jordan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name
ENAME	=	philo
NAME	=	philo.a
CFLAGS	=	
AR		=	ar -rsc
FILES	=	inc/mini_libft/ft_strdup.c inc/mini_libft/ft_itoa.c \
			main.c utils.c console.c thread.c

# Path for .c , .h and .o Files 
SRC_PATH := ./
OBJ_PATH := ./OBJ/

all : $(NAME)

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<     

# Build final Binary
$(NAME): $(OBJ)
	@echo [INFO] Creating $(Shell uname) Binary Executable [$(NAME)]
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS)
	$(CC) $(CFLAGS) $(NAME) -o $(ENAME)

# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*

fclean: clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(ENAME)

re: fclean all

san: all
	$(CC) $(CFLAGS) $(NAME) -fsanitize=address -o $(ENAME)

.PHONY : clean fclean re