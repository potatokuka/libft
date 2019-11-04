# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: greed <greed@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 10:31:09 by greed          #+#    #+#                 #
#    Updated: 2019/11/04 13:54:31 by greed         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS		=	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii\
	ft_isdigit ft_isprint ft_memccpy ft_memchr ft_memcpy ft_memmove\
	ft_memset ft_strchr ft_strlcat ft_strlcpy ft_strlen ft_strrchr\
	ft_strncmp ft_strnstr ft_tolower ft_toupper ft_calloc ft_memcmp\
	ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa\
	ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
CFILES		=	$(SRCS:%=srcs/%.c)
OFILES		=	$(CFILES:.c=.o)
INCLUDES	=	./includes
FLAGS		=	-Wall -Werror -Wextra -O2

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo "Done"

srcs/%.o: srcs/%.c
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean:
	@rm -f $(OFILES)

fclean: clean
	@echo "Cleaning: "
	@rm -f $(NAME)

re: fclean all
