SERVER	:= server
CLIENT	:= client
CC		:= cc
FLAGS	:= -Wall -Wextra -Werror -g

# Library Paths - No Spaces Around '='
LIBFT_DIR	:= libft
PRINTF_DIR	:= $(LIBFT_DIR)/ft_printf

# Source Files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Explicit Library Paths
LIBFT_A		:= $(LIBFT_DIR)/libft.a
PRINTF_A	:= $(PRINTF_DIR)/libftprintf.a

# Main Target
all: libft ft_printf $(SERVER) $(CLIENT)

# Executable Creation
$(SERVER): $(SRCS_SERVER)
	$(CC) $(FLAGS) -o $(SERVER) $(SRCS_SERVER) $(LIBFT_A) $(PRINTF_A)

$(CLIENT): $(SRCS_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT) $(SRCS_CLIENT) $(LIBFT_A) $(PRINTF_A)

# Library Compilation
libft:
	$(MAKE) -C $(LIBFT_DIR)

ft_printf: libft
	$(MAKE) -C $(PRINTF_DIR)

# Cleaning Rules
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re libft ft_printf