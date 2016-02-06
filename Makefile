all:
	g++ -Wall -Wextra -Wmain -W -Werror -pedantic-errors -pedantic -std=c++11 -O0 density.cpp -o board_fill_debug
	g++ -Wall -Wextra -Wmain -W -Werror -pedantic-errors -pedantic -std=c++11 -Ofast -march=native -fexpensive-optimizations density.cpp -o board_fill
