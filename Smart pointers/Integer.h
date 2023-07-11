#pragma once
#include <iostream>
class Integer
{
public:
	Integer();
	Integer(int iVal);
	Integer(const Integer& pc_other);
	Integer(Integer&& pc_other);
	~Integer();

	Integer& operator=(const Integer& pc_other);
	Integer& operator=(Integer&& pc_other);
	Integer operator+(const Integer& pc_other);
	Integer& operator++();
	Integer operator++(int);
	bool operator==(const Integer& pc_other) const;
	explicit operator int();

	void vSetVal(int iVal);
	int iGetVal() const;

	friend std::istream& operator>> (std::istream& in, Integer& pc_obj);
private:
	int* pi_val;
};

