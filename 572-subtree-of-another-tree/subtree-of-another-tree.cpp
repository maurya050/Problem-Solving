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
class Solution {
public:
    bool helper(TreeNode *node1, TreeNode *node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if((node1 == NULL && node2 != NULL) or (node1 != NULL && node2 == NULL) or (node1->val != node2->val))
            return false;
        
        return helper(node1->left, node2->left) and helper(node1->right, node2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot != NULL)
            return false;
        if(root->val == subRoot->val){
            if(helper(root, subRoot))
                return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
       
    }
};