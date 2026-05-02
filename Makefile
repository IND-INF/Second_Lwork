.PHONY: clean
CFLAGS = -Wall -g
OBJ = main.o sequence_test.o sequence_exceptions.o

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	del $(OBJ) main