// LeetCode #119 - Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/
// Topic: Array | Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {};
        for (int i=0; i<=rowIndex; i++) {
            if (i==0 or i==rowIndex) {
                result.push_back(1);
            }
            else {
                long long prev = result.back();
                long long next = prev * (rowIndex - i + 1) / i;
                result.push_back((int)next);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> result1 = sol.getRow(3);
    for (int x : result1) {
        cout << x << " ";
    }
    cout << " " << endl;

    vector<int> result2 = sol.getRow(0);
    for (int x : result2) {
        cout << x << " ";
    }
    cout << " " << endl;

    vector<int> result3 = sol.getRow(1);
    for (int x : result3) {
        cout << x << " ";
    }
    cout << " " << endl;
    return 0;
}