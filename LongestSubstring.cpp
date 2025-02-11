/*Given a string s, find the length of the longest substring without repeating characters.*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*This problem can be efficiently solved using the Sliding Window approach with a Hash Map
(unordered_map or vector for tracking character indices).

ie:
1. Initialize two pointers, left and right, to maintain a window of unique characters.
2. Use an unordered_map to store the index of the last occurence of a character.
3.Expand right to add new characters, but if a duplicate is found, move left to the right of the previous occurence
4. Keep track of the Maximum window size.
*/

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> charIndex; //Stores the last occurence of a characteer.
    int maxLength = 0, left =0;
    

    for(int right = 0; right < s.length(); right++){
        char currentChar = s[right];

        //If the character is found in the map and is within the window:
        if(charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left){
            left = charIndex[currentChar] + 1; //Move the left pointerahead of the last occurrence.
        }

        charIndex[currentChar] = right; //Update the last occurrence of the character.
        maxLength = max(maxLength, right - left +1); //Update max length.
    }

    return maxLength;
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Lenth of the longest substring without repeating characters: " <<lengthOfLongestSubstring(s);
}