// LeetCode #20 - Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
// Topic: String | Stack
// Level: Easy

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {

    Solution sol;
    string s1 = "()";
    bool sol1 = sol.isValid(s1);
    cout << "Solution is " << sol1 << endl;

    string s2 = "()[]{}";
    bool sol2 = sol.isValid(s2);
    cout << "Solution is " << sol2 << endl;

    string s3 = "(]";
    bool sol3 = sol.isValid(s3);
    cout << "Solution is " << sol3 << endl;

    string s4 = "([])";
    bool sol4 = sol.isValid(s4);
    cout << "Solution is " << sol4 << endl;

    string s5 = "([)]";
    bool sol5 = sol.isValid(s5);
    cout << "Solution is " << sol5 << endl;

    return 0;
}