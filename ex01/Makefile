#########################################
#				VARIABLES				#
#########################################

NAME = phonebook

# Compilation
CCX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
D_SRCS 			= srcs
D_INCS 			= incs
D_OBJS 			= objs

# Source Files (only .cpp files)
FILES 	= 	Contact.cpp \
			PhoneBook.cpp \
			main.cpp


SRCS		= 	$(addprefix $(D_SRCS)/, $(FILES))
INCS 		= 	-I ./$(D_INCS)
OBJS 		= 	$(patsubst $(D_SRCS)/%.cpp, $(D_OBJS)/%.o, $(SRCS))

#########################################
#				   RULES				#
#########################################

.PHONY : all
all: $(NAME)

$(D_OBJS)/%.o: $(D_SRCS)/%.cpp Makefile
	@mkdir -p $(dir $@)
	$(CCX) $(CXFLAGS) $(INCS) -c $< -o $@ 

$(D_OBJS):
	mkdir -p $(D_OBJS)

$(NAME): $(OBJS)
	$(CCX) $(CXFLAGS) $(OBJS) -o $(NAME)

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
