// LeetCode #13 - Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
// Topic: Hash Table | Math | String
// Level: Easy

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numbers = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'I' and (s[i+1] == 'V' or s[i+1] == 'X')) {
                result -= numbers['I'];
            }
            else {
                if (s[i] == 'X' and (s[i+1] == 'L' or s[i+1] == 'C')) {
                    result -= numbers['X'];
                }
                else {
                    if (s[i] == 'C' and (s[i+1] == 'D' or s[i+1] == 'M')) {
                        result -= numbers['C'];
                    }
                    else {
                        result += numbers[s[i]];
                    }
                }
            }
        }
        result += numbers[s[s.length()-1]];
        return result;
    }
};

// I should have written: if numbers[s[i]] < numbers[s[i+1]] then result -= numbers[s[i]] and else result += numbers[s[i]]

int main() {
    Solution sol;
    string word_1 = {"III"};
    int result_1 = sol.romanToInt(word_1);
    cout << result_1 << endl;

    string word_2 = {"LVIII"};
    int result_2 = sol.romanToInt(word_2);
    cout << result_2 << endl;

    string word_3 = {"MCMXCIV"};
    int result_3 = sol.romanToInt(word_3);
    cout << result_3 << endl;

    return 0;
}