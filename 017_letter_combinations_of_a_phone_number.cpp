// LeetCode #17 - Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Topic: Hash Table | String | Backtracking
// Level: Medium

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result = {""};
        unordered_map<char, string> values = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        auto aux = [&](char digit, vector<string> combinations) -> vector<string> {
            vector<string> results;
            for (char val : values[digit]) {
                for (string res : combinations) {
                    results.push_back(res + val);
                }
            }
            return results;
        };
        for (char digit : digits) {
            result = aux(digit, result);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words1 = sol.letterCombinations("23");

    for (string word : words1) {
        for (char letter : word) {
            cout << letter;
        }
        cout << endl;
        cout << "------" << endl;
    }
}