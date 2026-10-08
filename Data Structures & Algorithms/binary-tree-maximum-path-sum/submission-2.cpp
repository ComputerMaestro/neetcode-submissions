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
 DFS Approach :
Traverse the Tree in depth firt search manner and calculate the max path sum possible for a node within its subtree including the node. 
We need to track two things for each node First is the overal maxpathsum 
Second is the max sum possible including that node val 

For max sum , for any node, it would either:
    subtree root node value 
    subtree root node + max path value possible including left node 
    subtree root node + max path value possible including right node 
    max path in left subtree
    max path sum in right tee  
    subtree root node + max path value possible including right node  + max path value possible including left node 


For max possible value including the subtree root node value:
    subtree root node key value
    subtree root nod ekey value + max possible value including left node value
    subtree root nod ekey value + max possible value including right node value
    

why we do not include both side in this is because the path coming from parent can go either only one side , either left or right 
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return maxPathDFS(root).first;
    }

    pair<int, int> maxPathDFS(TreeNode *node) {
        if (node == nullptr) {
            return {-10000, -10000};
        }
        pair<int, int> l = maxPathDFS(node -> left);
        pair<int, int> r = maxPathDFS(node -> right);
        int maxSum = max({
            node -> val, 
            l.first, 
            r.first, 
            node -> val + l.second, 
            node -> val + r.second, 
            node -> val + l.second + r.second
        });
        int maxCurSum = max({
            node -> val,
            node -> val + l.second,
            node -> val + r.second
        });
        return {maxSum, maxCurSum};
    }
};
 