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

Traverse the tree and keep passing the largest value found upto that node for each node. 
we can return the value of the node if the largest value passed to is smaller than the current node value 
We can do this using dfs 
iterative method:
    we will have to keep track of two stacks, one will contain the nodes and other will contain largest value upto that node 
recursive method:
    we will keep passing the larger values along with the recursive calls and return the count + 1 is current node is good node 

we will have to use pre order traversal because we have to sent the largest value after compring current node with largest value , before sending the largest value to the sub tree of current node. 

 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return dfs(root, -1000);
    }

    int dfs(TreeNode* node, int largest) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;
        if (node -> val >= largest) {
            count++;
            largest = node -> val;
        }
        count += dfs(node -> left, largest);
        count += dfs(node -> right, largest);
        return count;
    }

};
