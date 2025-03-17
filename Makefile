a.out: main.o mohammad.o michael.o duran.o raj.o test.o
	g++ -g -fsanitize=address -std=c++17 main.o mohammad.o michael.o duran.o raj.o test.o

main.o: main.cc ll.h mohammad.h michael.h duran.h raj.h test.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC main.cc

mohammad.o: mohammad.cc mohammad.h ll.h particle.h particleSystem.h particleGraphics.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC mohammad.cc

michael.o: michael.cc michael.h ll.h particle.h particleSystem.h particleGraphics.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC michael.cc

duran.o: duran.cc duran.h ll.h particle.h particleSystem.h particleGraphics.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC duran.cc

raj.o: raj.cc raj.h ll.h particle.h particleSystem.h particleGraphics.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC raj.cc

test.o: test.cc test.h ll.h particle.h particleSystem.h particleGraphics.h
	g++ -g -c -fsanitize=address -std=c++17 -fPIC test.cc

clean:
	rm -f *.o a.out core
