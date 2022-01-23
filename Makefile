CC=g++ -Wall
RM=rm -f
SRC=$(wildcard *.cpp)
HEAD=$(wildcard *.hpp)
OBJ=$(SRC:.c=.o)
PROG=TP2ex2


$(PROG) : $(OBJ)			
	@$(CC) $^ -o $@  


%.o : ./src/%.c	
	$(CC) -c $^


.PHONY : clean

clean :
	@$(RM) *.o