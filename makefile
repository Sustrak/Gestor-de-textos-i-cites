OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
