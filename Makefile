# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 12:47:21 by lsilva-q          #+#    #+#              #
#    Updated: 2022/06/06 23:39:34 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
B_NAME			= pipex_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

INCLUDES_DIR	= includes
SRCS_DIR		= srcs
OBJS_DIR		= objs
B_OBJS_DIR		= b_objs
LIBS_DIR		= libraries

LFTX_DIR		= $(LIBS_DIR)/libft_x
LFTX			= $(LFTX_DIR)/libft_x.a
LFTX_FLAGS		=

SRC_FILES		= main/main.c												\
				  pipex/cmd_decoder.c	pipex/errors.c	pipex/pipex.c
B_SRC_FILES		= main/main_bonus.c											\
				  pipex/cmd_decoder_bonus.c		pipex/errors_bonus.c		\
				  pipex/pipex_bonus.c

SUBDIRS			= main pipex
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:%.c=%.o))
B_SRCS			= $(addprefix $(SRCS_DIR)/, $(B_SRC_FILES))
B_OBJS			= $(addprefix $(OBJS_DIR)/, $(B_SRC_FILES:%.c=%.o))

HEADER_FILES	= pipex.h pipex_bonus.h
HEADERS			= $(addprefix $(INCLUDES_DIR)/, $(HEADER_FILES))

I_CC			= -I $(INCLUDES_DIR) -I $(LFTX_DIR)

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c $(HEADERS)
				mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
				$(CC) $(CFLAGS) $(I_CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS) $(LFTX)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFTX)

$(LFTX):
				make -C $(LFTX_DIR)

clean:
				make clean -C $(LFTX_DIR)
				$(RM) $(OBJS)
				$(RM) $(B_OBJS)
				$(RM) -r $(OBJS_DIR)
				$(RM) -r $(B_OBJS_DIR)

fclean:			clean
				make fclean -C $(LFTX_DIR)
				$(RM) $(NAME)
				$(RM) $(B_NAME)

re:				fclean all

$(B_OBJS_DIR)/%.o : $(B_SRCS_DIR)/%.c $(HEADERS)
				mkdir -p $(B_OBJS_DIR) $(addprefix $(B_OBJS_DIR)/, $(SUBDIRS))
				$(CC) $(CFLAGS) $(I_CC) -c $< -o $@

bonus:			$(B_NAME)

$(B_NAME):		$(B_OBJS) $(LFTX)
				$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS) $(LFTX)
				cp $(B_NAME) $(NAME)

re_bonus:		fclean bonus

.PHONY:			all clean fclean re
