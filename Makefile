CC = gcc
CFLAGS = -g
TARGET = P0
OBJS = main.o buildTree.o traversal.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

buildTree.o: buildTree.c 
	$(CC) $(CFLAGS) -c buildTree.c 

traversal.o: traversal.c 
	$(CC) $(CFLAGS) -c traversal.c 

clean: 
	/bin/rm -f *.o $(TARGET)