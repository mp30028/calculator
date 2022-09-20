expr_calculator:
	g++ -Wall -fexceptions -g -c ./main.cpp -o ./obj/Debug/main.o
	g++ ./obj/Debug/main.o -o ./bin/Debug/expr_calculator.exe
clean:
	rm -f  ./obj/Debug/main.o ./bin/Debug/expr_calculator.exe
	touch ./main.cpp
