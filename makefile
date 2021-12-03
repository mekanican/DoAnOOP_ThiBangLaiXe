CC = g++

all: main.o question.o io.o
	$(CC) -o main main.o question.o io.o
main.o: main.cpp question.h io.h
	$(CC) -g -c main.cpp
question.o: question.cpp question.h constants.h
	$(CC) -g -c question.cpp
io.o: io.cpp io.h question.h
	$(CC) -g -c io.cpp
DatabaseClientUser.o: DatabaseClientUser.cpp DatabaseClientUser.h DatabaseClient.h
	$(CC) -g -c DatabaseClientUser.cpp

clean:
	rm -f *.o
	rm main