#include <iostream>
#include <vector>
#include <stdexcept>

#include "Polynom.h"

int main() {
	Polynom p(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	p *= p;
	std::cout << p;
}