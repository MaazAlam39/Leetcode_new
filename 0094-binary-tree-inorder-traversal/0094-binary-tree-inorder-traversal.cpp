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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if(root == NULL)
//             return res;
//         stack<TreeNode*> st;
//         TreeNode* cur = root;
//         while(cur != NULL || !st.empty())
//         {
//             while(cur != NULL)
//             {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             cur = st.top();
//             st.pop();
//             res.push_back(cur->val);
//             cur = cur->right;
//         }
//         return res;
        
//     }
// };



class Solution {
public:

    vector<int>ans;
    void inorder(TreeNode* root){
        if (root == NULL)return;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
       
        inorder(root);
        return ans;
    }
};