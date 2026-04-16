// LeetCode #27 - Remove Element
// https://leetcode.com/problems/remove-element/
// Topic: Array | Two Pointers
// Level: Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int no_elem_index = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[no_elem_index] = nums[i];
                no_elem_index += 1;
            }
        }
        return no_elem_index;
    }
};

int main() {
    Solution sol;
    vector<int> nums_1 = {3,2,2,3};
    int result_1 = sol.removeElement(nums_1, 3);
    cout << result_1 << endl;
    vector<int> nums_2 = {0,1,2,2,3,0,4,2};
    int result_2 = sol.removeElement(nums_2, 2);
    cout << result_2 << endl;
    return 0;
}