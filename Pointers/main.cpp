#include <iostream>
using namespace std;
int Add(int *a, int *b) {
	int res = *a + *b;		
	return res;
}
void AddVal(int* a, int* b, int* result) {	
	*result = *a + *b;	
}
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Factorial(int* a, int* result) {
	*result = 1;
	for (int i = 2; i <= *a; ++i)
		*result *= i;
}
int main() {
	int x = 5;
	int y = 6;
	cout << Add(&x, &y) << endl;
	int res{};
	AddVal(&x, &y, &res);
	cout << res << endl;
	Swap(&x, &y);
	cout << x << ' ' << y << endl;
	int res2{};
	Factorial(&x, &res2);
	cout << res2;
	return 0;
}