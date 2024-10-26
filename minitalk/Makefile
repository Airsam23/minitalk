# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 23:42:43 by sshamdin          #+#    #+#              #
#    Updated: 2023/07/19 23:42:54 by sshamdin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the names of the programs
NAMEC = client
NAMES = server

# Define the names of the source files
SRCC_FILES = client.c
SRCS_FILES = server.c

# Define the name of the library file
PRINTF = libftprintf.a

# Define the source directory
SRC_DIR = src/

# Define the full paths to the source files
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

# Define the object files that will be generated
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

# Define the compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Define the include directories
INCLUDE = -I include

# Define the command to remove files
RM = rm -rf

# The default target
all: $(NAMEC) $(NAMES)

# Target to build the client program
$(NAMEC): $(OBJC)
			# Build the printf library
			@make -C printf
			# Link the object files and the library to create the client program
			$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)

# Target to build the server program
$(NAMES): $(OBJS)
#Build the printf library
			@make -C printf
#Link the object files and the library to create the server program
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)

# Target to remove object files
clean:
# Remove object files from the printf library
	@make clean -C printf
# Remove the client and server object files
	@$(RM) $(OBJC)
	@$(RM) $(OBJS)

# Target to remove generated files
fclean: clean
# Remove the printf library
	@make fclean -C printf
# Remove the client and server programs
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(RM) $(PRINTF)

# Target to rebuild everything from scratch
re: fclean all

# Declare the phony targets
.PHONY: all clean fclean re
