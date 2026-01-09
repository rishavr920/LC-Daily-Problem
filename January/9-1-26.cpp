// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/


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
    unordered_map<int,int>mp;
    int maxD = 0;

    TreeNode* LCA(TreeNode* root){
        if(!root || mp[root->val] == maxD){
            return root;
        }

        TreeNode* leftResult = LCA(root->left);
        TreeNode* rightResult = LCA(root->right);

        if(leftResult != NULL and rightResult != NULL){
            return root;
        }

        if(leftResult == NULL) return rightResult;
        else if(rightResult == NULL)return leftResult;
        else return root;
    }
    void depth(TreeNode* root,int d){
        if(!root)return;

        maxD = max(maxD,d);
        mp[root->val] = d;
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);
        return LCA(root);
    }
};

// other way in only 1 pass
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
    pair<int,TreeNode*> solve(TreeNode* root){
        if(!root)return {0,NULL};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.first == right.first){
            return {left.first + 1,root};
        }
        else if(left.first > right.first){
            return {left.first + 1,left.second};
        }

        else{
            return {right.first + 1,right.second};
        }
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};