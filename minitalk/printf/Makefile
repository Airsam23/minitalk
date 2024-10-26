# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 00:10:05 by sshamdin          #+#    #+#              #
#    Updated: 2023/07/20 00:10:26 by sshamdin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Source Files
FT_PRINTF = ft_putchar.c ft_putnbr.c ft_putstr.c \
			ft_strlen.c ft_puthexa.c ft_print_s.c \
			ft_printf.c ft_uputnbr.c ft_putaddr.c \
		
#Converting suffix of Source files in Object files
OBJS			= $(FT_PRINTF:.c=.o)

#Compiler
CC				= cc

#Remove command
RM				= /bin/rm -rf

#Flags ('-I' add directory header file)
CFLAGS			= -Wall -Wextra -Werror -I.

#Name of the expected exec file
NAME			= libftprintf.a

#Rule to exec multiple commands at once
all:			$(NAME)

#Create a member from '$(OBJS)' in archive '$(NAME)'
#by copying the files from '$(OBJS)'
#The 'c' flag to ar is required if the archive file does not already exist. 
$(NAME):		$(OBJS)
				ar -rc $(NAME) $(OBJS)

.PHONY:			clean
clean:
				@$(RM) $(OBJS)

.PHONY:			fclean
fclean:			clean
				@$(RM) $(NAME)

#Cleans the files and remakes the library
.PHONY:			re
re:				fclean $(NAME)

.PHONY:			all clean fclean re
