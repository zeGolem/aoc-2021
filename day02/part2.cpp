/*
 * $ g++ part2.cpp -std=c++20 -Wall -Wextra -pedantic -o part2
 * $ ./part2 < example1.txt
 * [...]
 * Final value: 900
 */

#include <iostream>

struct position {
	int horizontal_position, depth, aim;
};

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	std::string command;
	int units;
	position submarine_pos{0, 0, 0};
	while (std::cin >> command >> units) {
		switch (command[0]) {
		case 'f':
			submarine_pos.horizontal_position += units;
			submarine_pos.depth += units * submarine_pos.aim;
			break;
		case 'd':
			submarine_pos.aim += units;
			break;
		case 'u':
			submarine_pos.aim -= units;
			break;
		default:
			std::cout << "Unrecognized command " << command << std::endl;
			throw;
		}
		std::cout << "Horizontal position: " << submarine_pos.horizontal_position
		          << ", depth: " << submarine_pos.depth << std::endl;
	}
	std::cout << "Final value: " << submarine_pos.horizontal_position * submarine_pos.depth
	          << std::endl;
}
