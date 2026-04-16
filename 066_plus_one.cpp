// LeetCode #66 - Plus One
// https://leetcode.com/problems/plus-one/
// Topic: Array | Math
// Level: Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l_digits = digits.size();
        int aux = 1;
        for (int i=l_digits-1; i >= 0; i--) {
            int sum = digits[i] + aux;
            int digit;
            if (sum > 9) {
                aux = 1;
                digit = sum % 10;
                if (i==0) {
                    digits[i] = digit;
                    digits.insert(digits.begin(), aux);
                    return digits;
                }
            }
            else {
                aux = 0;
                digit = sum;
            }
            digits[i] = digit;
        }
        return digits;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<int> result = sol.plusOne(nums);
    for (int x : result) cout << x << " ";
    cout << endl;
    vector<int> nums2 = {4,3,2,1};
    vector<int> result2 = sol.plusOne(nums2);
    for (int x : result2) cout << x << " ";
    cout << endl;
    vector<int> nums3 = {9};
    vector<int> result3 = sol.plusOne(nums3);
    for (int x : result3) cout << x << " ";
    cout << endl;
    return 0;
}