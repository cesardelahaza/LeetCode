// LeetCode #88 - Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Topic: Array | Divide and Conquer | Tree | Binary Search Tree | Binary Tree
// Level: Easy

#include <iostream>
#include <vector>
using namespace std;

/* 
Binary Search Tree (BST): tree in which each one of its nodes, values at left are smaller and values at right are bigger
Height-balanced: for each node, the difference between its left sub-tree and right sub-tree is at maximum 1.
*/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


class Solution {
public:
    TreeNode* tree_aux(vector<int>& nums, int left, int right) {
        int middle = (left + right)/2;
        if (left > right) {
            return nullptr;
        }
        else if (left == right) {
            return new TreeNode(nums[middle]);
        }
        return new TreeNode(nums[middle], tree_aux(nums, left, middle-1), tree_aux(nums, middle+1, right));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tree_aux(nums, 0, nums.size()-1);
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


int main() {
    Solution sol;
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* tree1 = sol.sortedArrayToBST(nums1);
    printInorder(tree1);
}