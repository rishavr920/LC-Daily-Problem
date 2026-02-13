// leetcode 3714
class Solution {
public:
    int solve1(string &s,int n){
        int count = 1; //s[0]
        int maxL = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        return maxL;
    }

    // case 2

    int solve2(string &s,int n,char first,char second){
        unordered_map<int,int>mp;
        int temp1 = 0;
        int temp2 = 0;
        int maxL = 0;

        for(int i=0;i<n;i++){
            if(s[i] != first and s[i] != second){
                mp.clear();
                temp1 = 0;
                temp2 = 0;
                continue;
            }
            if(s[i]==first)temp1++;
            else if(s[i]==second)temp2++;

            if(temp1==temp2){
                maxL = max(maxL,temp1+temp2);
            }
            int diff = temp1 - temp2;

            if(mp.find(diff) != mp.end()){
                maxL = max(maxL,i-mp[diff]);
            }
            else mp[diff] = i;
        }
        return maxL;
    }


    int solve3(string &s,int n){ //o(nlogn)
        int countA = 0;
        int countB = 0;
        int countC = 0;

        unordered_map<string,int>mp;
        int maxL = 0;

        for(int i=0;i<n;i++){ 
            if(s[i]=='a')countA++;
            else if(s[i]=='b')countB++;
            else if(s[i]=='c')countC++;

            if(countA==countB and countA==countC){
                maxL = max(maxL,countA+countB+countC);
            }
            int diffAB = countA-countB;
            int diffAC = countA-countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC); //log(n) digits

            if(mp.count(key)){
                maxL = max(maxL,i-mp[key]);
            }

            else mp[key] = i;
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int ans = INT_MIN;

        // case - 1 
        int case1 = solve1(s,n);

        // case - 2

        int case2 = max({solve2(s,n,'a','b'),solve2(s,n,'a','c'),solve2(s,n,'b','c')});

        // case - 3

        int case3 = solve3(s,n);

        return max({case1,case2,case3});
    }
};