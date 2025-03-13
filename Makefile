a.out: main.o mohammad.o michael.o duran.o raj.o
	g++ -g -fsanitize=address -std=c++17 main.o mohammad.o michael.o duran.o raj.o

main.o: main.cc ll.h mohammad.h michael.h duran.h raj.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC main.cc

mohammad.o: mohammad.cc mohammad.h ll.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC mohammad.cc

michael.o: michael.cc michael.h ll.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC michael.cc

duran.o: duran.cc duran.h ll.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC duran.cc

raj.o: raj.cc raj.h ll.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC raj.cc

clean:
	rm -f *.o a.out core
