// https://leetcode.com/problems/maximum-matrix-sum/description/
//myself

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negative_count = 0;
        int mini_number = INT_MAX;
        long long int total = 0;

        int n = matrix.size();
        int m = matrix[0].size();
        bool zero = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini_number = min(mini_number,abs(matrix[i][j]));

                if(matrix[i][j] < 0){
                    negative_count++;
                }
                else if(matrix[i][j] == 0){
                    zero = true;
                }
                total += abs(matrix[i][j]);
            }
        }
        if(negative_count%2==0){ //even h 
            return total;
        }
        else if(zero){
            return total;
        }
        return total - 2*mini_number;
    }
};