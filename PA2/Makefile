CXX_FLAG = --std=c++11 -g

all: builddep

builddep: builddep.o
	g++ ${CXX_FLAG} -o builddep builddep.o

clean:
	rm -f tenkinds *.o