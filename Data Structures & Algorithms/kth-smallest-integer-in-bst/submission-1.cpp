/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 For this we can just traverse the tree in order: 
 We just have to find the minimum value first and then keep traversing with adding 1 to the count and when  count is equal to the k , then we will return 
 we will know the minimum value when we reach the first node without any left child , that will the minimum node value 

 For this time complexity will be around: O(n) as will imght have to travel all the nodes 
 space compleixty will be O(n) for recusiion or iteration methods both
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, 0, k).first;
    }

    pair<int, int> dfs(TreeNode* node, int rank, int k) {
        if (node == nullptr) {
            return {-1, rank};
        }
        
        pair<int, int> l = dfs(node -> left, rank, k);
        if (l.second == k) {
            return l;
        }
        if (l.second + 1 == k) {
            return {node -> val, k};
        }
        pair<int, int> r = dfs(node -> right, l.second + 1, k);
        return r;
    }
};
