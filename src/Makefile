CC = g++
CXX = g++
CPPFLAGS = -I../include -std=c++11 -Wextra -g
LDFLAGS = -std=c++11

EXENAME = main test

.PHONY : clean TAGS all

all : $(EXENAME)
	mv $(EXENAME) ../

main : your_vector.o

main.o : main.cpp

your_vector.o : your_vector.cpp ../include/your_vector.h

clean :
	-rm -rf *.o *.dSYM

TAGS : clean all
