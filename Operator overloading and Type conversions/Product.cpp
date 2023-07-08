#include "Product.h"
#include <iostream>
using namespace std;
Product::Product(const Integer& pc_id):c_id(pc_id)
{
	//c_id = pc_id;
	cout << "Product()" << endl;
}

Product::~Product()
{
	cout << "~Product()" << endl;
}

Product::operator Integer()
{
	cout << "operator Integer" << endl;
	return c_id;
}
