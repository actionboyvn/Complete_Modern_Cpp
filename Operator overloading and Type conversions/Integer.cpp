#include "Integer.h"
#include <iostream>
using namespace std;
Integer::Integer() :Integer(0)
{
}

Integer::Integer(int iVal)
{
	pi_val = new int{ iVal };
	cout << "Integer()" << endl;
}

Integer::Integer(const Integer& pc_other)
{
	pi_val = new int{ pc_other.iGetVal() };
	cout << "Integer(const &)" << endl;
}

Integer::Integer(Integer&& pc_other)
{
	pi_val = pc_other.pi_val;
	pc_other.pi_val = nullptr;
	cout << "Integer(&&)" << endl;
}

Integer::~Integer()
{
	delete pi_val;
	cout << "~Integer()" << endl;
}

Integer& Integer::operator=(const Integer& pc_other)
{
	if (&pc_other != this) {
		delete pi_val;
		pi_val = new int{ pc_other.iGetVal() };
	}
	cout << "operator=" << endl;
	return *this;
}

Integer& Integer::operator=(Integer&& pc_other)
{
	delete pi_val;
	pi_val = pc_other.pi_val;
	pc_other.pi_val = nullptr;
	cout << "operator= move" << endl;
	return *this;
}

Integer Integer::operator+(const Integer& pc_other)
{
	cout << "operator+" << endl;
	return Integer(*pi_val + pc_other.iGetVal());
}

Integer& Integer::operator++()
{
	++(*pi_val);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer c_temp{ *this };
	++(*pi_val);
	return c_temp;
}

bool Integer::operator==(const Integer& pc_other) const
{	
	return *pi_val == pc_other.iGetVal();
}

Integer::operator int()
{
	return *pi_val;
}

void Integer::vSetVal(int iVal)
{
	if (pi_val == nullptr)
		pi_val = new int{};
	*pi_val = iVal;
}

int Integer::iGetVal() const
{
	return *pi_val;
}
