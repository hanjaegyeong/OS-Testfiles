#Makefile
CC = g++
try : Circle.o main.o
	g++ -g  Circle.o main.o -o erslab.out
main.o : main.cpp
	g++ -c  Circle.h
Circle.o : Circle.cpp
	g++ -c Circle.h
all : try

clean :
	rm -rf *.o *.out
