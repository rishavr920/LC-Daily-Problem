// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
class Solution {
public:
    int m,n;

    int dp[1001][1001];

    int solve(int i,int j,string& s1,string &s2){

        //agar dono out of bound ho jaye
        if(i>=m and j>=n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //agr i out of bound ho gaya,
        //to j ka bacha kisi kaam ka ni just add as ascii
        if(i>=m){
            return dp[i][j] = s2[j] + solve(i,j+1,s1,s2);
        }
        else if(j>=n){
            return dp[i][j] = s1[i] + solve(i+1,j,s1,s2);
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i+1,j+1,s1,s2);
        }

        // two possibilites
        int delete_s1_i = s1[i] + solve(i+1,j,s1,s2);
        int delete_s2_j = s2[j] + solve(i,j+1,s1,s2);

        return dp[i][j] = min(delete_s1_i,delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};