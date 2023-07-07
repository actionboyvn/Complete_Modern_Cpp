#include <iostream>
#include "Integer.h"
using namespace std;
std::ostream& operator<< (std::ostream& out, const Integer& pc_obj) {
	out << pc_obj.iGetVal();
	return out;
}
std::istream& operator>> (std::istream& in, Integer& pc_obj) {
	int x;
	in >> x;
	pc_obj.vSetVal(x);
	return in;
}
int main() {	
	Integer x(5);
	Integer y(7);
	Integer z;
	z = x + y;
	cout << z;
	return 0;
}