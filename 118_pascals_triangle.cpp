// LeetCode #118 - Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/
// Topic: Array | Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};
        if (numRows == 1) {
            return {{1}};
        }
        for (int row = 1; row < numRows + 1; row++) {
            vector<int> this_row = {};
            for (int elem = 0; elem < row; elem++) {
                if (elem == 0 or  elem == row-1) {
                    this_row.push_back(1);
                }
                else {
                    this_row.push_back(result[row-2][elem-1] + result[row-2][elem]);
                }
            }
            result.push_back(this_row);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> result1 = sol.generate(5);
    for (vector<int> row : result1) {
        for (int numb : row) {
            cout << numb << " ";
        }
        cout << " " << endl;
    }

    vector<vector<int>> result2 = sol.generate(1);
    for (vector<int> row : result2) {
        for (int numb : row) {
            cout << numb << " ";
        }
        cout << " " << endl;
    }

    return 0;


}