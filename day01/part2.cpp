/*
 * $ g++ part2.cpp -std=c++20 -Wall -Wextra -pedantic -o part2
 * $ ./part2 < example1.txt
 * [...]
 * Increased 5 times
 */

#include <iostream>
#include <optional>

struct shifting_int_triplet {
	std::optional<int> a;
	std::optional<int> b;
	std::optional<int> c;

	bool is_full() const { return a.has_value() && b.has_value() && c.has_value(); }

	void push(int const &new_val)
	{
		a = b;
		b = c;
		c = new_val;
	}

	int sum() const { return a.value() + b.value() + c.value(); }
};

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	int last_sum = -1;
	int increased_count = 0;
	int current_value;
	shifting_int_triplet triplet;
	while (std::cin >> current_value) {
		triplet.push(current_value);
		if (!triplet.is_full()) continue;
		int new_sum = triplet.sum();
		if (last_sum == -1) {
			std::cout << new_sum << " (N/A - no previous sum)" << std::endl;
			last_sum = new_sum;
			continue;
		}
		int diff = new_sum - last_sum;
		std::cout << new_sum << " " << ((diff > 0) ? "(increased)" : "(decreased)") << std::endl;
		if (diff > 0) ++increased_count;
		last_sum = new_sum;
	}
	std::cout << "Increased " << increased_count << " times" << std::endl;
}
