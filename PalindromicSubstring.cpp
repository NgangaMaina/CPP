//Finding the longest Palindromic substring in a string.

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1; // Track start index and max length

        for (int i = 0; i < s.length(); i++) {
            // Expand for odd-length palindromes
            expandAroundCenter(s, i, i, start, maxLen);
            // Expand for even-length palindromes
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
