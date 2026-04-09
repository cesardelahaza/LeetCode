// LeetCode #1 - Two Sum
// https://leetcode.com/problems/two-sum/
// Topic: Array | Hash Table

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexs;
        for (int i=0; i < nums.size(); i++) {
            if (indexs.count(nums[i])){
                return {indexs[nums[i]], i};
            }
            indexs.insert({target-nums[i], i});
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = sol.twoSum(nums, 9);
    cout << result[0] << ", " << result[1] << endl;
    vector<int> nums2 = {3,2,4};
    vector<int> result2 = sol.twoSum(nums2, 6);
    cout << result2[0] << ", " << result2[1] << endl;
    vector<int> nums3 = {3,3};
    vector<int> result3 = sol.twoSum(nums3, 6);
    cout << result3[0] << ", " << result3[1] << endl;
    return 0;
}