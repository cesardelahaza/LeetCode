// LeetCode #16 - 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// Topic: Array | Two Pointers | Sorting
// Level: Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sumy = nums[i] + nums[left] + nums[right];
                if (sumy == target) {
                    return target;
                }
                else if (sumy > target) {
                    right--;
                }
                else if (sumy < target) {
                    left++;
                }
                if (abs(target-sumy) < abs(target-result)) {
                    result = sumy;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-1,2,1,-4};
    int result1 = sol.threeSumClosest(nums1, 1);
    cout << result1 << endl;
    cout << "---------------------------" << endl;

    vector<int> nums2 = {0,0,0};
    int result2 = sol.threeSumClosest(nums2, 1);
    cout << result2 << endl;
    cout << "---------------------------" << endl;

    return 0;

}