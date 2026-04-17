// LeetCode #11 - Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Topic: Array | Two Pointers | Greedy
// Level: Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int amount = 0;
        while (left<right) {
            int area = (right - left) * min(height[left], height[right]);
            amount = max(amount, area);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return amount;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,8,6,2,5,4,8,3,7};
    int result1 = sol.maxArea(nums1);
    cout << result1 << endl;

    vector<int> nums2 = {1,1};
    int result2 = sol.maxArea(nums2);
    cout << result2 << endl;

    return 0;
}