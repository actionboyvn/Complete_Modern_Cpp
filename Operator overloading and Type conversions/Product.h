#pragma once
#include "Integer.h"
class Product
{
public:	
	Product(const Integer& pc_id);
	~Product();
	operator Integer();
	Integer c_id;
};

