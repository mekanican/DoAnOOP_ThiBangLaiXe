# CC = g++
# TARGET = main
# OBJ = DatabaseClientUser.o io.o Question.o main.o QuestionPack.o DatabaseClientQuestion.o
# CPP = DatabaseClientUser.cpp QuestionPack.cpp io.cpp Question.cpp main.cpp DatabaseClienQuestion.cpp
# DEPS = DatabaseClientUser.h DatabaseClient.h constants.h io.h Mode.h Question.h Score.h User.h QuestionPack.h DatabaseClienQuestion.h

# $(TARGET): $(OBJ)
# 	$(CC) $(OBJ) -std=c++2a -o $(TARGET)

# $(TARGET): $(OBJ)
# 	$(CC) $(OBJ) -o $(TARGET)

# clean:
# 	rm -f *.o
# 	rm $(TARGET)

CC = g++
all: main.o Question.o io.o DatabaseClientQuestion.o QuestionPack.o
	$(CC) -o main main.o Question.o io.o DatabaseClientQuestion.o QuestionPack.o
main.o: main.cpp QuestionPack.h
	$(CC) -g -c main.cpp
Question.o: Question.cpp Question.h constants.h
	$(CC) -g -c Question.cpp
io.o: io.cpp io.h Question.h
	$(CC) -g -c io.cpp
DatabaseClientQuestion.o: DatabaseClientQuestion.cpp DatabaseClientQuestion.h io.h
	$(CC) -g -c DatabaseClientQuestion.cpp
QuestionPack.o: QuestionPack.cpp QuestionPack.h
	$(CC) -g -c QuestionPack.cpp
User.o: User.cpp User.h
	$(CC) -g -c User.cpp
clean:
	rm -f *.o
	rm main