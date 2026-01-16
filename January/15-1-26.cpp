//me

// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxRow = n+2;
        int maxCol = m+2;
        // int totalArea = (maxRow-1)*(maxCol-1);

        int count1=1;
        int count2=1;

        int ans = 1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int c1 = 1,c2 = 1;

        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]+1==hBars[i]){
                count1++;
                c1 = max(c1,count1);
            }
            else count1 = 1;
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]+1==vBars[i]){
                count2++;
                c2 = max(c2,count2);
            }
            else{
                count2 = 1;
            }
        }
        int req = min(c1,c2);
        return (req+1)*(req+1);
    }
};