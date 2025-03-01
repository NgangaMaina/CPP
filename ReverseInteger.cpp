#include <iostream>
#include <climits> // INT_MAX, INT_MIN
using namespace std;

int reverse(int x) {
    int rev = 0; //Store the reversed number
     while(x != 0){
        int digit = x % 10; //Extract the last digit.

        //Check for overflow before multiplying by 10
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if(rev < INT_MIN / 10 || (rev == INT_MIN /10 && digit < -8)) return 0;

        rev  = rev * 10 + digit; //Append digigt to reversed number
        x /= 10; //Remove the last digit from X
     }

     return rev;
}

int main() {
    std::cout << reverse(123) << std::endl;    
    std::cout << reverse(-123) << std::endl;   
    std::cout << reverse(120) << std::endl;    
    std::cout << reverse(1534236469) << std::endl; 
    return 0;
}