# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: carlo <carlo@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 09:28:26 by cwesseli      #+#    #+#                  #
#    Updated: 2023/02/13 15:04:55 by cwesseli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m

NAME		= libft.a
CC			= clang
AR			= ar -rsc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror 
#-fsanitize=address -g
OBJ_FILES	=		$(addprefix obj/,ft_isalpha.o ft_strlen.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
						ft_toupper.o ft_tolower.o ft_atoi.o ft_bzero.o ft_strncmp.o ft_strlcat.o ft_strlcpy.o\
						ft_memchr.o ft_memcmp.o ft_strchr.o ft_memcpy.o ft_memset.o ft_memmove.o\
						ft_strnstr.o  ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_itoa.o\
						ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_striteri.o ft_strmapi.o ft_split.o\
						ft_putnbr_fd.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o\
						ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o\
						ft_lstiter_bonus.o ft_lstmap_bonus.o ft_putchar.o ft_putstr.o ft_isspace.o ft_wordcount.o\
						ft_printf.o ft_printf_chr_functions.o ft_printf_dec_functions.o ft_printf_checks.o\
						ft_printf_itoa.o get_next_line.o get_next_line_utils.o ft_free.o ft_free_array.o\
						ft_check_params.o ft_check_extention.o ft_free_array_int.o ft_strjoin_free.o)
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES)

$(OBJ_FILES): obj/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "$(BLUE)Cleaning libft$(RESET)"
	@$(RM) obj/

fclean: clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:	all clean fclean re