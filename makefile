CC = g++
LIBS =
CFLAGS = -Wall -std=c++11
OBJECTS = game.o
HFILES = board.h
TARGET = game.out
%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o *.out core