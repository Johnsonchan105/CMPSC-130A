CXX_FLAG = --std=c++11 -g

all: tenkinds

tenkinds: tenkinds.o
	g++ ${CXX_FLAG} -o tenkinds tenkinds.o

clean:
	rm -f tenkinds *.o

#all: tenkinds

#zoning: tenkinds.o
#	g++ ${CXX_FLAG} -o tenkinds tenkinds.o
#clean:
#	rm -f tenkinds *.o