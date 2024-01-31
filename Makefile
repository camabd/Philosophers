# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 12:30:49 by cabdli            #+#    #+#              #
#    Updated: 2024/01/31 18:48:09 by cabdli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

################################################################################
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
################################################################################

SRCS	=	main.c				\
			actions.c			\
			check_args.c		\
			collect_data.c		\
			init_threads.c		\
			init_variables.c	\
			routine_utils.c		\
			routine.c			\
			take_forks.c		\
			utils.c				\

################################################################################
#                                                                              #
#                                 VARIABLES                                    #
#                                                                              #
################################################################################

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -pthread 
#-fsanitize=address
# -fsanitize=thread -g3

OBJ		=	$(SRCS:.c=.o)

OFILES	=	.ofiles/

################################################################################
#                                                                              #
#                                	RULES                                      #
#                                                                              #
################################################################################

all:	$(NAME)

$(OFILES):
	@mkdir -p .ofiles

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OFILES)%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) $(addprefix $(OFILES), $(OBJ)) philo.h
	@$(CC) $(CFLAGS) $(addprefix $(OFILES), $(OBJ)) -o $@ -lpthread
	@echo "Making philo..."
	@echo "Ready !"
	
clean:
	@rm -rf $(OFILES)
	@echo "Making clean..."
	@echo "Done !"

fclean:	clean
	@rm -f $(NAME)
	@echo "philo deleted !"

re: fclean all

.PHONY: all re clean fclean
