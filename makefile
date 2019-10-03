main: Source.o Functions.o
	g++ -o main Source.o Functions.o
Source.o: Source.cpp
	g++ -c Source.cpp
Funkcijos.o: Functions.cpp
	g++ -c Functions.cpp
clean:
rm *.o *.txt main
