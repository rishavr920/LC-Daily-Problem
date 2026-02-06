// leetcode - 3634

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums),end(nums));

        int start = 0;
        int ans = INT_MIN;

        for(int end=0;end<n;end++){
            int mini = nums[start];
            int maxi = nums[end];

            if(maxi <= mini * (long long)k){
                ans = max(ans,end-start+1);
            }

            else{
                start++;
            }
        }
        return n-ans;
    }
};