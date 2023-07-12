#include <iostream>
long double operator"" _cm(long double val) {
	return long double{ val / 1000 };
}
long double operator"" _km(long double val) {
	return long double{ val * 1000 };
}
int main() {
	long double distance_m{ 500.0_cm };
	std::cout << distance_m << std::endl; // 0.5
	distance_m = 2.5_km;
	std::cout << distance_m << std::endl; // 2500
	return 0;
}