# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 15:05:53 by lbenatar          #+#    #+#              #
#    Updated: 2024/10/09 15:31:20 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET  = $(shell printf "\33[0m")
GREEN  = $(shell printf "\33[32m")

SRC	= src/exec_prog.c \
		src/init_data.c \
		src/utils.c \
		src/utils_2.c \
		src/exec_cmd_fille.c \
		src//utils_exec_cmd.c \

SRC_B	= src_bonus/exec_prog.c \
		src_bonus/init_data.c \
		src_bonus/utils.c \
		src_bonus/init_data_here.c \
		src_bonus/utils_here.c \
		src_bonus/get_next_line_utils.c \
		src_bonus/get_next_line.c \
		src_bonus/exec_cmd_fille.c \
		src_bonus/get_stdin_input.c \
		src_bonus/utils_exec_cmd.c \
		src_bonus/utils_2.c 

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Wextra -Werror

NAME = pipex.a

NAME_B = pipex_bonus.a

NAME_EXE = pipex

NAME_EXE_B = pipex_bonus

OBJ	= $(SRC:.c=.o)

OBJ_B	= $(SRC_B:.c=.o)

.c.o	:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME} libft

${NAME} : $(LIBFT) ${OBJ}
		@cp $(LIBFT) $(NAME)
		@ar rcs ${NAME} ${OBJ}
		cc ${CFLAGS} ./src/main.c -L. ${NAME} -o ${NAME_EXE}
		@echo "$(GREEN)$(NAME_EXE) successfully created!$(RESET)"

bonus : ${NAME_B} libft

${NAME_B} : $(LIBFT) ${OBJ_B}
		@cp $(LIBFT) $(NAME_B)
		@ar rcs ${NAME_B} ${OBJ_B}
		cc ${CFLAGS} ./src_bonus/main.c -L. ${NAME_B} -L. ${LIBFT} -o ${NAME_EXE_B}
		@echo "$(GREEN)$(NAME_EXE_B) successfully created (bonus)!$(RESET)"

$(LIBFT):
			@make --silent -C ./libft
			@echo "$(GREEN)LIBFT successfully compiled!$(RESET)"

clean :
		@rm -f ${OBJ}
		@rm -f ${OBJ_B}
		@rm -rf ./src/*.o
		@rm -rf ./src_bonus/*.o
		@make --silent -C ./libft clean
		@echo "$(GREEN)Successfully cleaned!$(RESET)"

fclean : clean
		@rm -f ${NAME}
		@rm -f ${NAME_EXE}
		@rm -f ${NAME_B}
		@rm -f ${NAME_EXE_B}
		@make --silent -C ./libft fclean
		@echo "$(GREEN)Successfully fcleaned!$(RESET)"

re : fclean all

.PHONY:	all clean fclean re libft
