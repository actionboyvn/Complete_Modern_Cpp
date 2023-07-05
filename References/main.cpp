#include <iostream>
using namespace std;

void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);            //Swap two numbers through reference arguments

int main() {
	int x{ 5 };
	int y{ 7 };
	int res{};
	Add(x, y, res);
	cout << res << endl;
	int res2{};
	Factorial(x, res2);
	cout << res2 << endl;
	Swap(x, y);
	cout << x << ' ' << y;
	return 0;
}

void Add(int a, int b, int& result) {
	result = a + b;
}

void Factorial(int a, int& result) {
	result = 1;
	for (int i = 2; i <= a; ++i)
		result *= i;
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}