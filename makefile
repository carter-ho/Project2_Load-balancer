all: test

test: loadbalancer.o request.o main.o
	g++ -g loadbalncer.o request.o main.o -o test

#loadbalancer.o: loadbalancer.h loadbalancer.cpp
#	g++ -c -g loadbalancer.cpp


#request.o: request.h request.cpp
#	g++ -c -g request.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm -f *.0 test

run: test
	./test