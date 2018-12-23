CC = g++
INC = ../inc/

test_lexer: test_lexer.cpp lexer.o
	$(CC) -o $@ $^ -I $(INC)

lexer.o: ../src/lexer.cpp
	$(CC) -c $< -I $(INC)

clean:
	rm test_lexer *.o