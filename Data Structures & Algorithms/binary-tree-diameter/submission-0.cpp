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
 */

struct BinTreeDiaLen{
    int dia;
    int maxLen;
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return getDiaAndMaxLen(root).dia;
    }

    BinTreeDiaLen getDiaAndMaxLen(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        int dia = 0;
        int maxLen = 0;
        BinTreeDiaLen l = {0, 0};
        BinTreeDiaLen r = {0, 0};
        if (node -> left) {
            l = getDiaAndMaxLen(node -> left);
            maxLen = l.maxLen + 1;
            dia++;
        }
        if (node -> right) {
            r = getDiaAndMaxLen(node -> right);
            maxLen = max(maxLen, r.maxLen + 1);
            dia++;
        }
        return {max({l.dia, r.dia, dia + l.maxLen + r.maxLen}), maxLen};
    }
};
