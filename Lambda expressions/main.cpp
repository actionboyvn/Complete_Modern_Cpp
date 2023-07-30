#include <iostream>
#include <vector>
using Comparator = bool(*)(int, int);
bool Comp(int x, int y) {
	return x > y;
}
void Sort(std::vector<int>& a, Comparator comp) {
	for (int i = 0; i < a.size() - 1; ++i)
		for (int j = i + 1; j < a.size(); j++)
			if (comp(a[i], a[j])) { // comp is invoked through address and can not be inlined
				int temp{ a[i] };
				a[i] = a[j];
				a[j] = temp;
			}
}
void FunctionPointers() {
	std::vector<int> a{6, 3, 4, 2, 5};
	Sort(a, Comp); // Comp doesn't have a state
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';
}

struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};
template<typename Comparator>
void Sort2(std::vector<int>& a, Comparator comp) {
	for (int i = 0; i < a.size() - 1; ++i)
		for (int j = i + 1; j < a.size(); j++)
			if (comp(a[i], a[j])) {
				int temp{ a[i] };
				a[i] = a[j];
				a[j] = temp;
			}
}
void FunctionObjects() {
	std::vector<int> a{6, 3, 4, 2, 5};
	Comp2 cmp;
	Sort2(a, cmp);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';
}

void SortWithLamdaExp() {
	std::vector<int> a{6, 3, 4, 2, 5};
	auto cmp = [](int x, int y) {
		return x > y;
	};
	Sort2(a, cmp);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';
}

template<typename T, typename Callback>
void ForEach(T& arr, int size, Callback operation) {
	for (int i = 0; i < size; ++i)
		operation(arr[i]);
}
void CaptureList() {
	std::vector<int> a{1, 2, 3};
	int k = 10, h = 0;
	ForEach(a, a.size(), [&k, h](int& x) mutable { // k is in the capture list
		x += k;
		k += 1;
		h += 2;
		});
	// k = 13, h = 0

	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';

	int j = 0;
	[=]() mutable{
		j += 1;
	}(); // All enclosing variables are captured by value

	[&]() mutable {
		j += 1;
	}(); // All enclosing variables are captured by pointer
	std::cout << std::endl << j;		
}

class Product {
	float f_price;
public:
	Product(float fPrice):f_price(fPrice) {
	}
	~Product() {
	}
	void vRaisePrice() {
		float taxes[]{ 5, 3.5, 3 };
		ForEach(taxes, 3, [this](float tax) {
			f_price += f_price * tax / 100;
		});
	}
	float fGetPrice() const{
		return f_price;
	}
};

void CapturePointerThis() {
	Product p{ 120 };
	std::cout << p.fGetPrice() << std::endl;

	p.vRaisePrice();
	std::cout << p.fGetPrice() << std::endl;
}

int main() {
	//FunctionPointers();
	//FunctionObjects();
	//SortWithLamdaExp();
	//CaptureList();
	CapturePointerThis();
	return 0;
}