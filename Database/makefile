CC = g++
TARGET = main
OBJ = DatabaseClientUser.o test.o
CPP = DatabaseClientUser.cpp test.cpp
DEPS = DatabaseClientUser.h DatabaseClient.h 

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp (DEPS)
	$(CC)	-c	%.cpp

clean:
	rm -f *.o
	rm $(TARGET)