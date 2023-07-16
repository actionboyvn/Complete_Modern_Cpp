#include <iostream>
#include <vector>
#include <string>

class Test {
public:
	Test() {
		std::cout << "Test()" << std::endl;
	}
	~Test() {
		std::cout << "~Test()" << std::endl;
	}
};

void Process(int x, int* y, int z) {
	if (x < 0)
		throw std::out_of_range("x can not be negative");
	if (y == nullptr)
		throw std::runtime_error("y can not be null");
}

void MultipleCatchBlocks() {
	Test* t = new Test(); // Memory leak when function throws an ex, use smart pointer here
	Test obj_test{}; // Objects will be properly destroyed when throws an ex
	try {
		//Process(-5, 0, 0);
		Process(5, nullptr, 0);
	}
	catch (std::runtime_error &ex) {
		std::cout << ex.what() << std::endl;
		//Handle the exception
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
		//Handle the exception
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		//Handle the exception
	}//For every exception
	catch (...) {
		std::cout << "Exception" << std::endl;
	}//For undefined exceptions -> Must be the last catch block
	
	delete t;
}

void NestedExceptions() {
	std::vector<int> records{5, 3, 2, -1, 3, -2, -4};
	int error_count{ 0 };	
	for (auto x : records) {
		try {
			if (x <= 0) {
				++error_count;
				throw std::runtime_error("Record " + std::to_string(x) + " can not be processed");
			}
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			if (error_count > 2) {
				std::runtime_error err("Too many error records");
				ex = err;
				throw;
			}
		}
	}		
}

class Base {
public:
	Base() {
		std::cout << "Base()" << std::endl;
	}
	~Base() {
		std::cout << "~Base()" << std::endl;
	}
};

class Member {
public:
	Member() {
		std::cout << "Member()" << std::endl;
	}
	~Member() {
		std::cout << "~Member()" << std::endl;
	}
};

class Derived : public Base {
	Member m; // Will be released when destructor throws an ex
	Member* p_m; // Won't be released when destructor throws an ex
public:
	Derived() {
		std::cout << "Derived()" << std::endl;
		p_m = new Member{};
		throw std::runtime_error("Failed to initialize Derived obj");
	}
	~Derived(){
		delete p_m;
		std::cout << "~Derived()" << std::endl;
		//throw std::runtime_error("Failed"); // Not allowed to throw in destructors

	} // Won't be invoked when destructor throws an ex

	Derived(Derived&& pc_other) noexcept(true){
		//Implementation
	} // Move constructor should be specified with noexcept true

	Derived& operator=(Derived&& pc_other) noexcept(true) {
		//Implementation
	} // Move assignment should be specified with noexcept true
};

void ExceptionsInConstructors() {
	try {
		Derived obj_d;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

int main() {
	//MultipleCatchBlocks();
	/*
	try {
		NestedExceptions();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}*/
	ExceptionsInConstructors();
	return 0;
}