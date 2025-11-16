#########################################
#				VARIABLES				#
#########################################

NAME = megaphone

# Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source Files
SRCS 	= 	megaphone.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

#########################################
#				   RULES				#
#########################################

.PHONY : all
all: $(NAME)

%.o: %.c Makefile 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ 


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY : clean
clean:
	@echo "clean objs from /$(NAME)"
	@rm -f $(OBJS)

.PHONY : fclean
fclean: 
	@$(MAKE) --no-print-directory clean
	@echo "clean $(NAME) from /$(NAME)"
	@rm -f $(NAME)

.PHONY : re
re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
