// LeetCode #35 - Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Topic: Array | Binary Search
// Level: Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = size(nums) -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums_1 = {1,3,5,6};
    int result_1 = sol.searchInsert(nums_1, 5);
    cout << result_1 << endl;
    vector<int> nums_2 = {1,3,5,6};
    int result_2 = sol.searchInsert(nums_2, 2);
    cout << result_2 << endl;
    vector<int> nums_3 = {1,3,5,6};
    int result_3 = sol.searchInsert(nums_3, 7);
    cout << result_3 << endl;
    return 0;
}