CC    = g++

FLAGS = -std=c++14 -g -Wall -Wunused-but-set-variable -pedantic -c

bintree:
	$(CC) $(FLAGS) Binary.cpp -o Binary.out


all:
		[path to CxxTest Files] --error-printer -o simple_testtree.cpp CxxTests/testtree.cpp
		[path to CxxTest Files] --error-printer -o simple_testbalance.cpp CxxTests/testbalance.cpp
		$(CC) $(FLAGS) Binary.cpp -o Binary.out
		g++ -std=c++14 -o test_testree.out -I [path to CxxTest Files] simple_testtree.cpp Binary.out
		g++ -std=c++14 -o test_testbalance.out -I [path to CxxTest Files] simple_testbalance.cpp Binary.out
		./test_testree.out
		./test_testbalance.out


clean:
	rm -f *.o *.out
