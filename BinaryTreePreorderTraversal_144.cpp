// Leetcode 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]
 
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 
// Follow up: Recursive solution is trivial, could you do it iteratively?

// Solution 1: recursive
// Time complexity: O(n) (n: number of nodes in the tree)
// Space complexity: O(h) (j: height of the tree)
vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> rst;
    preorderHelper(root, rst);
    return rst;
}
    
void preorderHelper(TreeNode* cur, vector<int>& cur_rst){
    if(cur == nullptr) return;
    cur_rst.push_back(cur->val);
    if(cur->left != nullptr) preorderHelper(cur->left, cur_rst);
    if(cur->right != nullptr) preorderHelper(cur->right, cur_rst);
}


// Solution 2: iterative with a stack
// Time complexity: O(n) (n: number of nodes in the tree)
// Space complexity: O(h) (j: height of the tree)
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> rst;
    if(root == nullptr) return rst;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* cur_node = s.top();
        s.pop();
        rst.push_back(cur_node->val);
        if(cur_node->right != nullptr) s.push(cur_node->right);
        if(cur_node->left != nullptr) s.push(cur_node->left);
    }
    
    return rst;
}