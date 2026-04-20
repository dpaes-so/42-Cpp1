# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 14:06:50 by dpaes-so          #+#    #+#              #
#    Updated: 2026/04/09 15:05:21 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp Serialization.cpp
SRCS_DIR = srcs
SRCS =	$(addprefix $(SRCS_DIR)/, $(SRC))

OBJS_DIR = objs
OBJ = $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)	
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS)  -c $< -o $@
	
$(OBJS_DIR):
	@echo COMPILING...
	@mkdir -p $(OBJS_DIR)
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all