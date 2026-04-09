// LeetCode #26 - Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Topic: Array | Two Pointers

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[c] = nums[i];
                c++;
            }
        }
        return c;
    }
};

int main() {
    Solution sol;
    vector<int> nums_1 = {1,1,2};
    int result_1 = sol.removeDuplicates(nums_1);
    cout << result_1 << endl;
    vector<int> nums_2 = {0,0,1,1,1,2,2,3,3,4};
    int result_2 = sol.removeDuplicates(nums_2);
    cout << result_2 << endl;
    return 0;
}