COMPILE_ARG = -c
LINK_ARG    = 

neuron.o: neuron.h neuron.cpp
	g++ $(COMPILE_ARG) neuron.cpp

main.o: main.cpp neuron.h
	g++ $(COMPILE_ARG) main.cpp

all: neuron.o main.o
	g++ *.o
