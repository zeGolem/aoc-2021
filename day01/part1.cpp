/*
 * $ g++ part1.cpp -std=c++20 -Wall -Wextra -pedantic -o part1
 * $ ./part1 < example1.txt
 * [...]
 * Increased 7 times
 */

#include <iostream>

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	int last_measurement = -1;
	int new_measurement = 0;
	int increased_count = 0;
	while (std::cin >> new_measurement) {
		if (last_measurement == -1) {
			std::cout << new_measurement << " (N/A - no previous measurement)" << std::endl;
			last_measurement = new_measurement;
			continue;
		}
		int diff = new_measurement - last_measurement;
		std::cout << new_measurement << " " << ((diff > 0) ? "(increased)" : "(decreased)")
		          << std::endl;
		if (diff > 0) ++increased_count;
		last_measurement = new_measurement;
	}
	std::cout << "Increased " << increased_count << " times" << std::endl;
}
