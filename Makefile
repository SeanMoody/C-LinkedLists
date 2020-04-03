CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = a8
DEP1 = linkedlist

all: $(DEP1) $(TARGET)

$(DEP1): $(DEP1).c
	$(CC) $(CFLAGS) -c $(DEP1).c

$(TARGET): $(TARGET).c $(DEP1).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(DEP1).o

clean:
	rm $(TARGET) $(DEP1).o