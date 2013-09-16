all: program.exe

program.exe: main.o functie.o
	g++ main.o functie.o -o program.exe -O0 -Wall
main.o: main.cpp
	g++ -c main.cpp
functie.o: functie.cpp
	g++ -c functie.cpp

clean:
	rm *.o *.exe
