CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = twixt
OBJS = control.o board.o winchecking.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

control.o: control.c twixt.h winchecking.h
	$(CC) $(CFLAGS) -c control.c

board.o: board.c twixt.h
	$(CC) $(CFLAGS) -c board.c

winchecking.o: winchecking.c winchecking.h twixt.h
	$(CC) $(CFLAGS) -c winchecking.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run