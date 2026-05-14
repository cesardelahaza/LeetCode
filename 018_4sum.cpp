// LeetCode #18 - 4Sum
// https://leetcode.com/problems/4sum/
// Topic: Array | Two Pointers | Sorting
// Level: Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 and nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++)
            {
                if (j!=i+1 and nums[j] == nums[j-1])
                {
                    continue;
                }
                else
                {
                    int left = j + 1;
                    int right = nums.size() - 1;
                    while (left < right)
                    {
                        if ((long long)target -(nums[i] + nums[j]) == (long long) nums[left] + nums[right])
                        {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            left++;
                            right--;
                            while (nums[left - 1] == nums[left] and left < right)
                            {
                                left++;
                            }
                            while (nums[right + 1] == nums[right] and left < right)
                            {
                                right--;
                            }
                        }
                        else if ((long long)target-(nums[i] + nums[j]) < (long long) nums[left] + nums[right])
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
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result1 = sol.fourSum(nums1, 0);
    for (vector<int> x : result1)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    vector<vector<int>> result2 = sol.fourSum(nums2, 8);
    for (vector<int> x : result2)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    vector<int> nums3 = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> result3 = sol.fourSum(nums3, -294967296);
    for (vector<int> x : result3)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout << " " << endl;
    }
    cout << "---------------------------" << endl;

    return 0;
}