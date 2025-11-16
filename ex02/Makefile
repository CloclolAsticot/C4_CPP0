#########################################
#				VARIABLES				#
#########################################

NAME = account

# Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

# Directories
D_SRCS 			= srcs
D_INCS 			= incs
D_OBJS 			= objs

# Source Files (only .cpp files)
FILES 	= 	Account.cpp \
			tests.cpp \

SRCS		= 	$(addprefix $(D_SRCS)/, $(FILES))
INCS 		= 	-I ./$(D_INCS)
OBJS 		= 	$(patsubst $(D_SRCS)/%.cpp, $(D_OBJS)/%.o, $(SRCS))
DEPS		=	$(patsubst $(D_SRCS)/%.cpp, $(D_OBJS)/%.d, $(SRCS))

#########################################
#				   RULES				#
#########################################

.PHONY : all
all: $(D_OBJS) $(NAME)

$(D_OBJS)/%.o: $(D_SRCS)/%.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCS) -c $< -o $@ 

$(D_OBJS):
	mkdir -p $(D_OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

.PHONY : clean
clean:
	@echo "clean objs from /$(NAME)"
	@rm -rf $(D_OBJS)

.PHONY : fclean
fclean: 
	@$(MAKE) --no-print-directory clean
	@echo "clean $(NAME) from /$(NAME)"
	@rm -f $(NAME)

.PHONY : re
re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
