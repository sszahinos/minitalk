# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:33:55 by sersanch          #+#    #+#              #
#    Updated: 2022/12/13 15:19:22 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
SRV_NAME	= server
CLI_NAME	= client
LBF_NAME	= libft.a 

HEADER	= minitalk.h
INCLUDE	= -I 
SRC_DIR	= src
OBJ_DIR	= obj
DEP_DIR = dep
INC_DIR = include
LBF_DIR = utils/libft
TST_DIR = test

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
RMALL	= rm -rf
AR		= ar -rcs
MKDIR	= mkdir -p
MV		= mv -f

#### FORMAT #####
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
LMAGENTA	:= \033[95m


##### FILES #####
SRC_SRV_FILES	= server
SRC_CLI_FILES	= client

SRC_SRV	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_SRV_FILES)))
OBJ_SRV	= $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_SRV_FILES)))
DEP_SRV	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_SRV_FILES)))

SRC_CLI	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_CLI_FILES)))
OBJ_CLI	= $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_CLI_FILES)))
DEP_CLI	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_CLI_FILES)))


##### RULES #####
all: make_libft folders $(SRV_NAME) $(CLI_NAME)

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) $(LBF_DIR)/$(LBF_NAME) Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(SRV_NAME): $(OBJ_SRV)
	@make import_utils
	@$(AR) $(SRV_NAME) $(OBJ_SRV)
	@echo "$(BOLD)$(LMAGENTA)$(NAME) $(GREEN)compilated succesfully!$(RESET)"

$(CLI_NAME): $(OBJ_CLI)
	@$(AR) $(CLI_NAME) $(OBJ_CLI)
	@echo "$(BOLD)$(LMAGENTA)$(NAME) $(GREEN)compilated succesfully!$(RESET)"

make_libft:
	@make -C $(LBF_DIR)

clean:
	@make clean -C $(LBF_DIR)
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(SRV_NAME)$(YELLOW) and $(CYAN)$(CLI_NAME) \
	$(YELLOW)objects and dependencies deleted.$(RESET)"

fclean: clean
	@$(RM) $(SRV_NAME) $(CLI_NAME)
	@make fclean -C $(LBF_DIR)
	@echo "$(CYAN)$(SRV_NAME)$(YELLOW) and $(CYAN)$(CLI_NAME) \
	$(YELLOW)deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)

push:
	git add *.c Makefile *.h && git commit -m "Functions updated" && git push

folders:
	@$(MKDIR) $(SRC_DIR)/$(OBJ_DIR)
	@$(MKDIR) $(SRC_DIR)/$(DEP_DIR)

import_utils:
	@cp $(LBF_DIR)/$(LBF_NAME) ./$(NAME)
	@echo "$(GREEN)Imported $(CYAN)$(LBF_NAME)$(RESET)"

test:
	@make re
	@$(CC) $(CFLAGS) $(NAME) $(TST_DIR)/$(TST_FILES)
	@echo "$(GREEN)Test compiled$(RESET)"
	@./a.out

test_paco:
	@echo "$(CYAN)Executing francinette $(YELLOW)standard $(CYAN)mode$(RESET)"
	@/Users/sersanch/francinette/tester.sh -in
	@echo "$(CYAN)Executing francinette $(YELLOW)strict $(CYAN)mode$(RESET)"
	@/Users/sersanch/francinette/tester.sh -s -in

-include $(DEP_SRV)
-include $(DEP_CLI)

.PHONY: all clean fclean re norm folders make_libft folders import_utils test test_paco
