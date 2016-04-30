CC = g++
CFLAGS = -g -Wall -std=c++11

all: mazemake mazesolve mazeshow clean

mazemake: mazemake.o mazegrid.o dset.o
	$(CC) $(CFLAGS) -o $@ mazemake.o mazegrid.o dset.o

mazemake.o: mazemake.cpp mazegrid.h
	$(CC) $(CFLAGS) -c mazemake.cpp
	
mazesolve: mazesolve.o mazegrid.o dset.o
	$(CC) $(CFLAGS) -o $@ mazesolve.o mazegrid.o dset.o
	
mazesolve.o: mazesolve.cpp mazegrid.h
	$(CC) $(CFLAGS) -c mazesolve.cpp

mazeshow: mazeshow.o mazegrid.o dset.o
	$(CC) $(CFLAGS) -o $@  mazeshow.o mazegrid.o dset.o
	
mazeshow.o: mazeshow.cpp mazegrid.h
	$(CC) $(CFLAGS) -c mazeshow.cpp

mazegrid.o: mazegrid.cpp mazegrid.h
	$(CC) $(CFLAGS) -c mazegrid.cpp

dset.o: dset.cpp dset.h
	$(CC) $(CFLAGS) -c dset.cpp
	
clean:
	rm -f mazemake.o mazesolve.o mazeshow.o mazegrid.o dset.o