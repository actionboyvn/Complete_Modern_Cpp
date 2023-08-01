#pragma once
class Integer
{
public:
	Integer();
	Integer(int iVal);
	Integer(const Integer& pc_other);
	Integer(Integer&& pc_other) noexcept; // Move operations must not throw any exceptions
	~Integer();

	Integer& operator=(const Integer& pc_other);
	Integer& operator=(Integer&& pc_other) noexcept; // Move operations must not throw any exceptions
	Integer operator+(const Integer& pc_other);
	void vSetVal(int iVal);
	int iGetVal() const;
private:
	int* pi_val;
};

