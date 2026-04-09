// LeetCode #14 - Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Topic: Array | String | Trie

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int c=0; c < strs[0].length(); c++) {
            char single_char = strs[0][c];
            for (int word=1; word < strs.size(); word++) {
                if (single_char != strs[word][c]) {
                    return result;
                }
            }
            result += single_char;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words_1 = {"flower","flow","flight"};
    string result_1 = sol.longestCommonPrefix(words_1);
    cout << result_1 << endl;
    vector<string> words_2 = {"dog","racecar","car"};
    string result_2 = sol.longestCommonPrefix(words_2);
    cout << result_2 << endl;
    vector<string> words_3 = {"a"};
    string result_3 = sol.longestCommonPrefix(words_3);
    cout << result_3 << endl;
    return 0;
}