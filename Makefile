all:
	rm -f yet_another_getopt.*
	clang-3.5 -Wall -Werror -lstdc++ main.cpp -o yet_another_getopt.clang
	/usr/bin/g++ -Wall -Werror -lstdc++ main.cpp -o yet_another_getopt.gcc
	./yet_another_getopt.gcc -m data
	./yet_another_getopt.gcc --iterations 300
	./yet_another_getopt.gcc -m mc --iterations 400
	./yet_another_getopt.gcc -p 100
