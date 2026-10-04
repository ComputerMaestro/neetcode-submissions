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
 
 DFS approach:
 we can traverse the tree using DFS and in that also pass kind of indicator which will tell whether we have encountered the p and q nodes 
 we need to find the meeting node of the sub trees in which p and q are present basically
 first we need to find the p and q themselves 
 for this we can simple use two booleans we traverse and return two booleans which will tell whether the sub tree has p node or not and q node or not. 
 On the node in which these both are true that node is the lowest common ancestor for these two 

 we can solve this recursive or by iterative method using stack

 Since in worst case we will have to travel each node twice the time comlexity will be O(n)
 and space complexity will also be O(n) in both recursive as well as iterative method
 we would want to traverse the tree in post order because we want to set booleans for each node , basically booleans tell that whether this node has p or q in its tree or not , and that is something we can only set in post order

 we can further optimize this by storing these booleans in bits in a single value instead of separted booleans variables
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        tuple<TreeNode*, bool, bool> res = lca(root, p -> val, q -> val);
        return get<0>(res);
    }

    tuple<TreeNode*, bool, bool> lca(TreeNode *node, int p , int q) {
        if (node == nullptr) {
            return make_tuple(nullptr, false, false);
        }
        tuple<TreeNode*, bool, bool> l = lca(node -> left, p, q);
        tuple<TreeNode*, bool, bool> r = lca(node -> right, p, q);
        if (get<0>(l)) {
            return l;
        } else if(get<0>(r)) {
            return r;
        }
        bool isP = false, isQ = false;
        if (get<1>(l) || get<1>(r) || node -> val == p) {
            isP = true;
        }
        if (get<2>(l) || get<2>(r) || node -> val == q) {
            isQ = true;
        }
        if (isP && isQ) {
            return make_tuple(node, true, true);
        }
        return make_tuple(nullptr, isP, isQ);
    }
}; 

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         stack<TreeNode*> st;
//         st.push(root);
//         TreeNode *lastVisited = nullptr;
//         map<TreeNode*, pair<bool, bool>> pqAncestor;
//         while(!st.empty()) {
//             TreeNode* curNode = st.top();
//             if(curNode -> left) {
//                 st.push(curNode -> left);
//             } else {
//                 if (curNode -> right && lastVisited != curNode -> right) {
//                     st.push(curNode -> right);
//                 } else {
//                     bool pPresent = false, qPresent = false;
//                     if (pqAncestor[curNode -> left].first || curNode -> val == p -> val) {
//                         pPresent = true;
//                     }
//                     if (pqAncestor[curNode -> right].first || curNode -> val == q -> val) {
//                         qPresent = true;
//                     }
//                     if (pPresent && qPresent) {
//                         return curNode;
//                     }
//                     pqAncestor[curNode] = pair<bool, bool>(pPresent, qPresent);
//                     lastVisited = curNode;
//                     st.pop();
//                 }
//             }
//         }
//         return root;
//     }
// };
