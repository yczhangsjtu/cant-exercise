/**
 * The exercise is to write a multi-precision package
 * To save effort, use the boost multi-precision package
 * Then this exercise is just a hello world for this
 * package
 **/

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main() {
	using boost::multiprecision::cpp_int;
	cpp_int factorial = 1;
	cpp_int limit = (cpp_int(1) << 128) - 1;
	unsigned i = 1;
	while(factorial < limit) {
		factorial *= i;
		i++;
		std::cout << factorial << std::endl;
	}
	return 0;
}