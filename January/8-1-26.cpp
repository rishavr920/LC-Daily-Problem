// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    int m, n;
    // m = length of nums1
    // n = length of nums2

    int t[501][501];
    // DP table
    // t[i][j] stores the maximum dot product
    // using subsequences starting from index i in nums1
    // and index j in nums2

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {

        // ❌ Base case:
        // If we reach the end of either array,
        // we cannot form a valid subsequence
        if (i == m || j == n) {
            return -1e9;  // acts as negative infinity
        }

        // ✅ If already computed, return stored result
        if (t[i][j] != -1e9) {
            return t[i][j];
        }

        // 🧮 Dot product of current elements
        int val = nums1[i] * nums2[j];

        // 1️⃣ Take both elements (i and j)
        // Move forward in both arrays
        int take_i_j = val + solve(nums1, nums2, i + 1, j + 1);

        // 2️⃣ Skip current element of nums2
        int take_i = solve(nums1, nums2, i, j + 1);

        // 3️⃣ Skip current element of nums1
        int take_j = solve(nums1, nums2, i + 1, j);

        // 🔥 Choose the maximum of all possible options
        return t[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        // Store sizes of both arrays
        m = nums1.size();
        n = nums2.size();

        // Initialize DP table with negative infinity
        // because the result can be negative
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }

        // Start recursion from index (0, 0)
        return solve(nums1, nums2, 0, 0);
    }
};
