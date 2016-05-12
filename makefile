OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Cjt_cites.o Cjt_textos.o Cita.o Biblioteca.o Frase.o Text.o Func_auxiliars.o Taula.o
	g++ -o program.exe program.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_cites.o: Cjt_cites.cc Cjt_cites.hh
	g++ -c Cjt_cites.cc $(OPCIONS)

Cjt_textos.o: Cjt_textos.cc Cjt_textos.hh
	g++ -c Cjt_textos.cc $(OPCIONS)

Cita.o: Cita.cc Cita.hh
	g++ -c Cita.cc $(OPCIONS)

Biblioteca.o: Biblioteca.cc Biblioteca.hh
	g++ -c Biblioteca.cc $(OPCIONS)

Frase.o: Frase.cc Frase.hh
	g++ -c Frase.cc $(OPCIONS)

Text.o: Text.cc Text.hh
	g++ -c Text.cc $(OPCIONS)

Func_auxiliars.o: Func_auxiliars.cc Func_auxiliars.hh
	g++ -c Func_auxiliars.cc $(OPCIONS)

Taula.o: Taula.cc Taula.hh
	g++ -c Taula.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
