#include <iostream>
#include <vector>



#define Square(x) x*x
using namespace std;
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

inline int iSquare(int x) {
    return x * x;
}


int main() {
    /*
    //Number n{ 5 };
    //Print(n);
    int x = 3;
    //int y = iSquare(x + 1);
    int y = Square((x + 1));
    std::cout << y;*/

    return 0;
}