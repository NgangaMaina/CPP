#include <iostream>

int add(int a, int b){
    return a + b;
}

class calculator{
    public:
    int multiply(int a, int b){
        return a * b;
    }
};

int main(){
    int x = 5;
    int y = 3;

    int sum = add(x, y);
    std::cout << "sum: " << sum << std::endl;

    calculator calc;
    int product = calc.multiply(x, y);
    std::cout << "product: " << product << std::endl;

    return 0;
}