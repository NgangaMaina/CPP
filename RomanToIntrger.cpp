#include <iostream>
#include <vector>

using namespace std;

class RomanToInteger {
   public:
   string intToRoman(int num){
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };  

    string result = ""; //Store the final roman numeral rrepresentation

    //Iterate through the values and subtruct while appending the roman numeral
    for (auto &[value, symbol] : roman) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }
    return result;
   }
};

int main() {
    RomanToInteger solution;
    int num;

    cout << "Enter a number (1-3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << "Invalid input! Number must be between 1 and 3999." << endl;
    } else {
        cout << "Roman numeral: " << solution.intToRoman(num) << endl;
    }
    
    return 0;
}