#include <iostream>

class solution {
    public:
    bool isPalindrome(int x){
        //Negative numbers and numbers that end in 0 (Except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10; // Extract last digit and add to the reversedHalf
            x /= 10; //Remove last digit from x
        }

        //Check if original half matches the reversedHalf
        return x == reversedHalf || x == reversedHalf /10;
    }
};