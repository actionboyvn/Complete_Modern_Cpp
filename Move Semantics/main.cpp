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
void Swap(Integer& x, Integer& y) {
	Integer temp{std::move(x)};
	x = std::move(y);
	y = std::move(temp);
	/*Integer temp{ x };
	x = y;
	y = temp;*/
}
int main() {	
	Integer x(5);
	Integer y(7);
	/*Integer z;
	z = x + y;
	cout << z;*/

	Swap(x, y);
	cout << x;
	cout << y;
	return 0;
}