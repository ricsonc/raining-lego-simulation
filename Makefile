all:
	g++ -Wall -Wextra -Wmain -W -Werror -pedantic-errors -pedantic -std=c++0x -O0 main.cpp -o board_fill_debug
	g++ -Wall -Wextra -Wmain -W -Werror -pedantic-errors -pedantic -std=c++0x -Ofast -march=native -fexpensive-optimizations main.cpp -o board_fill
