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

Two Arrays Solution:
We can use two arrays, curLevelNodes, nextLevelNodes
curLevelNodes holds the values of nodes which is being processed right not 
processing of node means storing its key value into the final output nested 2d array and the left and right pointer into nextLevelNodes
nextLevelNodes holds the pointers to the nodes on the next level which will be processed once the curLevelNodes are done 
basically after all curLevelNodes are processed we will replace curLevelNodes = nextLevelNodes 
nextLevelNodes will be empty 

This way we will only have to processed each node only once which will give us O(n) time complexity
But since we are using this extra two arrays O(2^h) h = logn => n => O(n)

Breath first search solution:
we can simply use BFS implementation using queue (FIFO) property using which we can easily traverse the tree breadth wise

 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> levelWiseTraversal;
        vector<int> levelValues;
        vector<TreeNode*> curLevelNodes = {root}, nextLevelNodes;
        while(curLevelNodes.size() > 0) {
            levelValues = {};
            for(int i = 0; i < curLevelNodes.size(); i++) {
                levelValues.push_back(curLevelNodes[i] -> val);
                if (curLevelNodes[i] -> left) {
                    nextLevelNodes.push_back(curLevelNodes[i] -> left);
                }
                if (curLevelNodes[i] -> right) {
                    nextLevelNodes.push_back(curLevelNodes[i] -> right);
                }
            }
            levelWiseTraversal.push_back(levelValues);
            curLevelNodes = nextLevelNodes;
            nextLevelNodes = {};
        }
        return levelWiseTraversal;
    }
};
