// LeetCode #88 - Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/
// Topic: Array | Two Pointers | Sorting
// Level: Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n_aux = 0;
        int m_aux = 0;
        while (m_aux < m or n_aux < n) {
            if (m_aux < m and n_aux >= n) {
                nums1[(m + n)-1 - (m_aux + n_aux)] = nums1[m-1 - m_aux];
                m_aux += 1;
            }
            else if (n_aux < n and m_aux >= m) {
                nums1[(m + n)-1 - (m_aux + n_aux)] = nums2[n-1 - n_aux];
                n_aux += 1;
            }
            else {
                if (nums1[m-1 - m_aux] < nums2[n-1 - n_aux]) {
                    nums1[(m + n)-1 - (m_aux + n_aux)] = nums2[n-1 - n_aux];
                    n_aux += 1;
                }
                else {
                    nums1[(m + n)-1 - (m_aux + n_aux)] = nums1[m-1 - m_aux];
                    m_aux += 1;
                }
            }
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums_11 = {1,2,3,0,0,0};
    int m_1 = 3;
    vector<int> nums_12 = {2,5,6};
    int n_1 = 3;
    sol.merge(nums_11, m_1, nums_12, n_1);
    for (int x : nums_11) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> nums_21 = {1};
    int m_2 = 1;
    vector<int> nums_22 = {};
    int n_2 = 0;
    sol.merge(nums_21, m_2, nums_22, n_2);
    for (int x : nums_21) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> nums_31 = {0};
    int m_3 = 0;
    vector<int> nums_32 = {1};
    int n_3 = 1;
    sol.merge(nums_31, m_3, nums_32, n_3);
    for (int x : nums_31) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> nums_41 = {2,0};
    int m_4 = 1;
    vector<int> nums_42 = {1};
    int n_4 = 1;
    sol.merge(nums_41, m_4, nums_42, n_4);
    for (int x : nums_41) {
        cout << x << " ";
    }
    cout << endl;
}