// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
// one way of doing 

class Solution {
public:
    int mod = 1e9+7;

    // To store the maximum product
    long long ans = 0;

    // To store total sum of tree
    long long totalSum = 0;

    // Function to calculate total sum using DFS
    void calculateTotalSum(TreeNode* root) { //inorder traversal to find su

        // Base case
        if (!root) return;

        // Recur left
        calculateTotalSum(root->left);

        // Recur right
        calculateTotalSum(root->right);

        // Add current node value
        totalSum += root->val;
    }

    // Function to compute subtree sums and update max product
    long long dfs(TreeNode* root) {

        // Base case
        if (!root) return 0;

        // Get left subtree sum
        long long leftSum = dfs(root->left);

        // Get right subtree sum
        long long rightSum = dfs(root->right);

        // Current subtree sum
        long long currSum = leftSum + rightSum + root->val;

        // Remaining part after cutting this subtree
        long long remaining = totalSum - currSum;

        // Update maximum product
        ans = max(ans, currSum * remaining);

        // Return subtree sum
        return currSum;
    }

    int maxProduct(TreeNode* root) {

        // Step 1: Calculate total sum
        calculateTotalSum(root);

        // Step 2: Try every possible split
        dfs(root);

        // Return result (mod is usually asked in LeetCode)
        return ans % mod;
    }
};

// another way using mik

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
    long sum = 0;
    long maxP = 0;
    int MOD = 1e9+7;
    
    int totalSum(TreeNode* root){
        if(!root)return 0;

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        long subtreeSum = root->val+leftSubtreeSum+rightSubtreeSum;
        long remainingSubtreeSum = sum - subtreeSum;
        maxP = max(maxP,subtreeSum*remainingSubtreeSum);
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(!root)return 0;

        maxP = 0;
        sum = totalSum(root);
        totalSum(root);

        return maxP%MOD;
    }
};