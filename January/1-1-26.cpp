//link -  https://leetcode.com/problems/plus-one/description/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //2 case 
        //first -> last digit is not 9.
        //second -> if last digit is 9.

        int n = digits.size();
        //solve first case
        if(digits[n-1]!=9){
            digits[n-1] = 1 + digits[n-1];
        }
        else{
            int carry = 1;
            for(int i=n-1;i>=0;i--){
                if(carry){
                    int temp = digits[i];
                    temp++;
                    if(temp==10){
                        digits[i] = 0;
                        carry = 1;
                    }
                    else{
                        digits[i] = temp;
                        carry = 0;
                    } 
                }
                else{
                    continue;
                }
            }
            if(carry){
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};