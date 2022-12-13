# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 11:42:15 by sersanch          #+#    #+#              #
#    Updated: 2022/12/13 12:21:37 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME	= libft.a

HEADER	= libft.h
INCLUDE	= -I 
PATH	= utils/libft
SRC_DIR	= src
OBJ_DIR	= obj
DEP_DIR = dep
INC_DIR	= include

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
RMALL	= rm -rf
AR		= ar -rcs
MKDIR	= mkdir -p

#### FORMAT #####
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
LMAGENTA	:= \033[95m


##### FILES #####
SRC_FILES =	ft_atoi \
			ft_atoi_bin \
			ft_itoa \
			ft_itoa_bin \
			ft_itodec

#### NAMING #####
SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ	= $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
DEP	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_FILES)))

##### RULES #####
all: folders $(NAME)

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) Makefile 
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) ./$(INC_DIR)/$(HEADER) -c $< -o $@
	@mv $(SRC_DIR)/$(OBJ_DIR)/$*.d $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@touch $(NAME) 
	@echo "$(BOLD)$(LMAGENTA)$(NAME) $(GREEN)compilated succesfully!$(RESET)"

clean:
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME) $(YELLOW)objects and dependencies deleted.$(RESET)"

fclean: clean #--> Clean executed on main Makefile
	@$(RM) $(NAME)
#	@$(RMALL) ./$(PATH)/$(SRC_DIR)/$(OBJ_DIR) ./$(PATH)/$(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME) $(YELLOW)$(YELLOW)deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)

push:
	git add ft_*.c && git commit -m "Functions updated" && git push

folders:
	@$(MKDIR) $(SRC_DIR)/$(OBJ_DIR)
	@$(MKDIR) $(SRC_DIR)/$(DEP_DIR)

-include $(DEP)

.PHONY: all clean fclean re norm folders
