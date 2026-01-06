//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06
//by myself
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1;
        int ans = -1;
        q.push(root);
        
        int maxSum = INT_MIN;
        
        while(!q.empty()){
            int n = q.size();
            int tempSum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                tempSum += temp->val;
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
            if(tempSum > maxSum){
                    maxSum = tempSum;
                    ans = level;
            }
            level++;
        }
        return ans;
    }
};