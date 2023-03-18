# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile_ori                                       :+:    :+:             #
#                                                      +:+                     #
#    By: carlo <carlo@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 09:28:26 by cwesseli      #+#    #+#                  #
#    Updated: 2023/03/18 19:02:07 by carlo         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

NAME		= pipex
CC			= clang
CFLAGS		= -Wall -Wextra -Werror 
#-fsanitize=address -g

LIBFT		= ./libft
LIBS		= $(LIBFT)/libft.a 
HEADERS		= -I $(LIBFT)
OBJ_FILES	= $(addprefix obj/, pipex.o utils.o utils2.o utils3.o error_free.o fork.o\
				pipes.o)

all: libft $(NAME)

bonus: all

libft:
	@$(MAKE) -C $(LIBFT)
	
$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(LIBS) $(HEADERS) $(ARCFLAGS) -o $(NAME) $(CFLAGS)

$(OBJ_FILES): obj/%.o: src/%.c 
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) $(HEADERS) -o $@ $< 

clean:
	@echo "$(BLUE)Cleaning$(RESET)"
	@rm -rf obj/
	@$(MAKE) -C $(LIBFT) clean
	
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:	all bonus clean fclean re libft
