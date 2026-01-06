//link -  https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        n = n/2;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto i:mp){
            if(i.second==n){
                return i.first;
            }
        }
        return 0;
    }
};

//optimal approach in constant space

//we know that in nums array repeat elements are n times while other are just one.

//so in array 50% area are taken by repeated elements and in 50% remaining present.

//therfore if we see current element with previous or their previous i definitely get the repeated.

//Approach-3 (Without using any extra variable to store space - True Constant Space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 2; i<n; i++) {
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2])
                return nums[i];
        }
        
        return nums[0]; //TO handles cases like [1, 1, 2, 3] or [1, 2, 3, 1] only fail at 4 sized array
    }
};
// ⚡ Why this works

// Repeated element appears N times

// Other elements appear only once

// So repeated number must collide with nearby elements