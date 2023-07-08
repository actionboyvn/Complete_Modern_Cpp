#include <iostream>
#include "Integer.h"
#include "Product.h"
using namespace std;
std::ostream& operator<< (std::ostream& out, const Integer& pc_obj) {
	out << pc_obj.iGetVal();
	return out;
}
std::istream& operator>> (std::istream& in, Integer& pc_obj) {
	int x;
	in >> x;
	*pc_obj.pi_val = x;
	return in;
}
void TestOperators() {
	Integer x{ 5 };
	Integer y{ 5 };
	cout << (x == y) << endl;
}
void TestAssignmentOperator() {
	Integer x{};
	x = Integer{ 2 };
	Integer z{ 5 };
	x = z;
	z = z;
	cout << z << endl;
}
void TestCastsOnPrimitiveTypes() {
	int a = 5, b = 7;
	cout << static_cast<float>(b) / a << endl;
	char* p = reinterpret_cast<char*>(&a);
	cout << *p << endl;
	const int x = 1;
	const int* q = const_cast<int*>(&x);	
	cout << x << endl;
}
void TestCastsFromUserDefinedToPrimitive() {
	Integer x{ 5 };
	int y = static_cast<int>(x);
	cout << y;
}
void TestCastsBetweenUserDefined() {	
	Product p{ 5 };
	Integer x;
	x = p; // x = p.operator Integer();
	
	Integer id{ 5 };
	if (id == p) // id == p.operator Integer();
		cout << "Ids match" << endl;
}
void TestMemberInitializationList() {
	Product p{ 5 };	
	Integer x;
	x = 5;
}
int main() {
	//TestOperators();
	//TestAssignmentOperator();
	//TestCastsOnPrimitiveTypes();
	//TestCastsBetweenUserDefined();
	//TestMemberInitializationList();
	return 0;
}