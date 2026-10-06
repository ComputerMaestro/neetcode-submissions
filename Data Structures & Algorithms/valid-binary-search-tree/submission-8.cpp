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

DFS or BFS , traverse the tree and for each node we can check whether the BST property holds or not 
Both can be done recursively or iteratively 

Try with iterative solution using DFS:


for Tree to be BST 
each node should have smaller values in left tree 
and all values in right sub tree to be larger and its own value 

for this 
each node shoulde be less than the minimum value of its right sub tree 
each node should be greater than the maximum value of it left sub tree

so basically we will have to keep track of the maximum in left sub tree and minimum in right sub tree
from bottom up

We can do this using DFS 
TIme complexity O(n) 
space complexity O(n)

 */
struct DfsBSTMinMax {
    bool isValid;
    int minimum;
    int maximum;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTWithMinAndMax(root).isValid;
    }

    DfsBSTMinMax isValidBSTWithMinAndMax(TreeNode* node) {
        int minimum , maximum;
        if(node -> left) {
            if(node -> val > node -> left -> val) {
                DfsBSTMinMax l = isValidBSTWithMinAndMax(node -> left);
                if (!l.isValid) {
                    return {false, 0, 0};
                } else if (l.maximum >= node -> val) {
                    return {false, 0, 0};
                } else {
                    minimum = l.minimum;
                }
            } else {
                return {false, 0, 0};
            }
        } else {
            minimum = node -> val;
        }
        if(node -> right) {
            if(node -> val < node -> right -> val) {
                DfsBSTMinMax r = isValidBSTWithMinAndMax(node -> right);
                if (!r.isValid) {
                    return {false, 0, 0};
                } else if (r.minimum <= node -> val) {
                    return {false, 0, 0};
                } else {
                    maximum = r.maximum;
                }
            } else {
                return {false, 0, 0};
            }
        } else {
            maximum = node -> val;
        }
        return {true, minimum, maximum};
    }
};
