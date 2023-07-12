#include <iostream>
#include <vector>


class Base {
public:
    int i_public{};
private:
    int i_private{};
protected:
    int i_protected{};
};

class Child : private Base {
public:
    void vPrint() {
        std::cout << i_public;
    }
};

int main() {
    Child c;
    c.i_public;

    return 0;
}