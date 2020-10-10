CFLAGS = -O -std=c++17
CC = g++

SRC = Main.cpp PortScanner/PortScanner.cpp -lsfml-system -lsfml-network
OBJ = $(SRC:.cpp = .o)
Main: $(OBJ)
	$(CC) $(CFLAGS) -o Main.o $(OBJ)
clean:
	rm -f core *.o 