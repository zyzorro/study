
all:dir.o
	gcc -o dir dir.o
dir.o: dir.c
	gcc  -g -c dir.c -o dir.o

fork:fork.o
	gcc -o fork fork.o
fork.o:fork.c
	gcc -g -c fork.c -o fork.o
	
error:error.c
	gcc -g -o error error.c

cpptest:cpptest.cpp
	g++ -g cpptest.cpp  -o test

clean:
	rm -rf *.o dir fork error test

