# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:33:55 by sersanch          #+#    #+#              #
#    Updated: 2023/01/31 11:12:40 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME		= minitalk
SRV_NAME	= server
CLI_NAME	= client
LBF_NAME	= libft.a

SRV_NAME_BONUS	= server_bonus
CLI_NAME_BONUS	= client_bonus

HEADER	= minitalk.h
HEADER_BONUS = minitalk_bonus.h

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

SRC_SRV_FILES_BONUS	= server_bonus
SRC_CLI_FILES_BONUS	= client_bonus

##### OBJECTS AND DEPENDENCIES #####
SRC_SRV	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_SRV_FILES)))
OBJ_SRV = $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_SRV_FILES)))
DEP_SRV	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_SRV_FILES)))

SRC_CLI	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_CLI_FILES)))
OBJ_CLI = $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_CLI_FILES)))
DEP_CLI	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_CLI_FILES)))

##### BONUS OBJECTS AND DEPENDENCIES #####
SRC_SRV_BONUS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_SRV_FILES_BONUS)))
OBJ_SRV_BONUS = $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_SRV_FILES_BONUS)))
DEP_SRV_BONUS = $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_SRV_FILES_BONUS)))

SRC_CLI_BONUS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_CLI_FILES_BONUS)))
OBJ_CLI_BONUS = $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_CLI_FILES_BONUS)))
DEP_CLI_BONUS = $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_CLI_FILES_BONUS)))


##### RULES #####
all: make_libft folders $(NAME) 

bonus: make_libft folders $(OBJ_SRV_BONUS) $(OBJ_CLI_BONUS) $(SRV_NAME_BONUS) $(CLI_NAME_BONUS) #$(NAME_BONUS)

$(NAME): $(OBJ_SRV) $(OBJ_CLI) $(SRV_NAME) $(CLI_NAME)

#$(NAME_BONUS): $(OBJ_SRV_BONUS) $(OBJ_CLI_BONUS) $(SRV_NAME_BONUS) $(CLI_NAME_BONUS)
#	@echo "NO se ejecuta"

##### OBJ COMPILER #####
$(OBJ_SRV): $(SRC_SRV) $(INC_DIR)/$(HEADER) $(LBF_DIR)/$(LBF_NAME) Makefile
	@rm -f server
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(OBJ_CLI): $(SRC_CLI) $(INC_DIR)/$(HEADER) $(LBF_DIR)/$(LBF_NAME) Makefile
	@rm -f client
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

##### EXEC COMPILER #####
$(SRV_NAME): 
	@$(CC) $(CFLAGS) $(INCLUDE) $(INC_DIR)/$(HEADER) $(OBJ_SRV) $(LBF_DIR)/$(LBF_NAME) -o $(SRV_NAME)
	@echo "$(BOLD)$(LMAGENTA)$(SRV_NAME) $(GREEN)compilated succesfully!$(RESET)"

$(CLI_NAME):
	@$(CC) $(CFLAGS) $(INCLUDE) $(INC_DIR)/$(HEADER) $(OBJ_CLI) $(LBF_DIR)/$(LBF_NAME) -o $(CLI_NAME)
	@echo "$(BOLD)$(LMAGENTA)$(CLI_NAME) $(GREEN)compilated succesfully!$(RESET)"



##### BONUS OBJ COMPILER #####
$(OBJ_SRV_BONUS): $(SRC_SRV_BONUS) $(INC_DIR)/$(HEADER_BONUS) $(LBF_DIR)/$(LBF_NAME) Makefile
	@rm -f $(SRC_SRV_FILES_BONUS)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER_BONUS) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(OBJ_CLI_BONUS): $(SRC_CLI_BONUS) $(INC_DIR)/$(HEADER_BONUS) $(LBF_DIR)/$(LBF_NAME) Makefile
	@rm -f $(SRC_CLI_FILES_BONUS)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER_BONUS) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

##### BONUS EXEC COMPILER #####
$(SRV_NAME_BONUS): 
	@$(CC) $(CFLAGS) $(INCLUDE) $(INC_DIR)/$(HEADER_BONUS) $(OBJ_SRV_BONUS) $(LBF_DIR)/$(LBF_NAME) -o $(SRV_NAME_BONUS)
	@echo "$(BOLD)$(LMAGENTA)$(SRV_NAME_BONUS) $(GREEN)compilated succesfully!$(RESET)"

$(CLI_NAME_BONUS):
	@$(CC) $(CFLAGS) $(INCLUDE) $(INC_DIR)/$(HEADER_BONUS) $(OBJ_CLI_BONUS) $(LBF_DIR)/$(LBF_NAME) -o $(CLI_NAME_BONUS)
	@echo "$(BOLD)$(LMAGENTA)$(CLI_NAME_BONUS) $(GREEN)compilated succesfully!$(RESET)"

make_libft:
	@make -C $(LBF_DIR)

clean:
	@make clean -C $(LBF_DIR)
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(SRV_NAME)$(YELLOW) and $(CYAN)$(CLI_NAME) \
	$(YELLOW)objects and dependencies deleted.$(RESET)"

clean_bonus:
	@make clean -C $(LBF_DIR)
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@$(RM) $(SRV_NAME_BONUS) $(CLI_NAME_BONUS)
	@echo "$(CYAN)Bonus $(YELLOW)executables, \
	$(YELLOW)objects and dependencies deleted.$(RESET)"

fclean: clean
	@make clean_bonus
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

#import_utils:
#	@cp $(LBF_DIR)/$(LBF_NAME) ./$(NAME)
#	@echo "$(GREEN)Imported $(CYAN)$(LBF_NAME)$(RESET)"

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

.PHONY: all clean fclean re norm make_libft folders test test_paco
