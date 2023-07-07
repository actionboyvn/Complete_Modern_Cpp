#pragma once
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
	void vSetVal(int iVal);
	int iGetVal() const;
private:
	int* pi_val;
};

