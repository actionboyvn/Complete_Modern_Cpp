#include <iostream>
class Number {
    int m_Num{};
public:
    Number(int num) {
        m_Num = num;
    }
    int GetNumber() const{
        return m_Num;
    }
    //Constructors and other members
};

void Print(const Number& num) {
    std::cout << num.GetNumber();
}

int main() {
    Number n{ 5 };
    Print(n);
    //Other code
    return 0;
}