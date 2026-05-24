// LeetCode #12 - Integer to Roman
// https://leetcode.com/problems/integer-to-roman/
// Topic: Hash Table | Math | String
// Level: Medium

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<pair<int, string>> esp_values = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        for (pair<int, string >& p : esp_values) {
            while (num >= p.first) {
                result += p.second;
                num -= p.first;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string word_1 = sol.intToRoman(3749);

    for (char c : word_1) {
        cout << c;
    }
    cout << endl;

    string word_2 = sol.intToRoman(58);

    for (char c : word_2) {
        cout << c;
    }
    cout << endl;

    string word_3 = sol.intToRoman(1994);

    for (char c : word_3) {
        cout << c;
    }
    cout << endl;

    return 0;
}