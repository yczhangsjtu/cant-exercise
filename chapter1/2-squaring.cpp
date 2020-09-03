#include <boost/multiprecision/cpp_int.hpp>
#include <boost/timer/timer.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;


cpp_int square_base(cpp_int x, uint e) {
	if(e == 0) return x*x;

	cpp_int a = x >> e;
	cpp_int b = x - (a << e);
	cpp_int a2 = square_base(a, e/2);
	cpp_int b2 = square_base(b, e/2);
	cpp_int ab2 = square_base(a+b, e/2);
	return (a2 << (e*2)) + ((ab2 - a2 - b2) << e) + b2;
}

cpp_int square(cpp_int x) {
	if(x == 0) return 0;
	if(x < 0) return square(-x);
	if(x == 1) return 1;

	cpp_int a = x;
	uint e = 0;
	while(a > 0) {
		a >>= 1;
		e++;
	}

	return square_base(x, e/2);
}

int main() {
	for(int i = 0; i < 100; i++) {
		std::cout << i << "^2 = " << square(cpp_int(i)) << std::endl;
	}

	cpp_int a = 100000;
	{
		boost::timer::auto_cpu_timer t;
		for(int i = 0; i < 10; i++) {
			a = square(a);
		}
	}
	cpp_int b = 100000;
	{
		boost::timer::auto_cpu_timer t;
		for(int i = 0; i < 10; i++) {
			b = b * (b+1);
		}
	}
	return 0;
}