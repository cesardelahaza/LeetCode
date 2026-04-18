// LeetCode #15 - 3Sum
// https://leetcode.com/problems/3sum/
// Topic: Array | Two Pointers | Sorting
// Level: Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 and nums[i] == nums[i-1])
            {
                continue;
            }
            else
            {
                int left = i+1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (-nums[i] == nums[left] + nums[right])
                    {
                        result.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while (nums[left-1] == nums[left] and left < right) {
                            left++;
                        }
                        while (nums[right+1] == nums[right] and left < right) {
                            right--;
                        }
                    }
                    else if (-nums[i] < nums[left] + nums[right])
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    for (vector<int> x : result1) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    vector<int> nums2 = {0,1,1};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    for (vector<int> x : result2) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    vector<int> nums3 = {0,0,0};
    vector<vector<int>> result3 = sol.threeSum(nums3);
    for (vector<int> x : result3) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    vector<int> nums4 = {-100,-70,-60,110,120,130,160};
    vector<vector<int>> result4 = sol.threeSum(nums4);
    for (vector<int> x : result4) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;
    return 0;

}