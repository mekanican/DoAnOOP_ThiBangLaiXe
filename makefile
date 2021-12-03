CC = g++
TARGET = main
OBJ = DatabaseClientUser.o io.o Question.o test.o 
CPP = DatabaseClientUser.cpp io.cpp Question.cpp test.cpp
DEPS = DatabaseClientUser.h DatabaseClient.h constants.h io.h Mode.h Question.h Score.h User.h

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp (DEPS)
	$(CC)	-c	%.cpp

clean:
	rm -f *.o
	rm $(TARGET)