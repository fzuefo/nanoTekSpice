##
## EPITECH PROJECT, 2020
## MY MAKEFILES
## File description:
## the ultimate makefile
##

vpath %.cpp src
vpath %.cpp src/errorHandling
vpath %.cpp src/regex
vpath %.cpp src/componant

.RECIPEPREFIX =	-


NAME	=	nanotekspice
OBJECT	=	obj
SOURCES	=	sources

###################
## Compil option ##
###################

CC      =       g++
CFLAG   =       -W -Wall -Wextra \
                -Wno-unused-variable \
		-std=c++20
###########
## imput ##
###########


FILE =  main.cpp ErrorHandling.cpp Parcing.cpp Data.cpp DataComponent.cpp DataLink.cpp libRegex.cpp	\
	Tristate.cpp \
 Componant.cpp Pin.cpp loop.cpp \
	Board.cpp \
	Factory.cpp \
	Logic.cpp \
	utilitary.cpp \
	Mono.cpp \
	Creator.cpp

DIR_INCLUDE = -I include/ -I ./
DIR_LIB =

SRC_LIB = 

BLACK_LIST_SRC = 

###########
### OBJ ###
###########

ALL_OBJ =       $(patsubst %.cpp, $(OBJECT)/%.o, $(SRC))

SRC	=	$(filter-out $(BLACK_LIST_SRC), $(FILE))

############
### RULE ###
############

.PHONY: all re clean folder fclean 
.DEFAULT: all

all:	Folder $(NAME)
-@echo	-e "\e[32mlinking compliete\e[39m"

$(NAME): Form_preCompil $(ALL_OBJ)
-@g++ -o $(NAME) $(ALL_OBJ) $(DIR_LIB) $(SRC_LIB) -g3

Folder:	|	$(OBJECT)

clean:
-@echo -e "\e[33m-->Cleaning time\e[00m"
-rm -f ./$(OBJECT)/*.o

fclean:	clean
-rm -rf $(OBJECT)
-rm -f $(NAME)

re:	clean all

###################
### INTERN RULE ###
###################
        ##dialogue rule
Form_preCompil:
-@echo -e "\n\e[1;94mCompilation start\e[0m"

        ##dir generate
$(OBJECT):
-@echo -e "\e[95mOBJ Directory Generate\e[0m"
-@mkdir -p $(OBJECT)

       ##target: $() = destiantion final; depandance: $(sources)/ = fichier de base
$(OBJECT)/%.o	: %.c
-@$(CC) -c -o $@ $< $(CFLAG) $(DIR_INCLUDE) -g
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"

$(OBJECT)/%.o	: %.cpp
-@$(CC) -c -o $@ $< $(CFLAG) $(DIR_INCLUDE) -g
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"
