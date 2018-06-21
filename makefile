main: main.cpp menu.cpp menu.h tensor.h tensor.cpp test.h test.cpp

	g++ main.cpp menu.cpp tensor.cpp test.cpp

clean:

	rm  a.out

start:

	./a.out
