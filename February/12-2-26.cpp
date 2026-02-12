class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        unordered_map<char,int>mp;

        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                int k = mp[s[j]];
                int flag = 0;
                for(auto it:mp){
                    cout<<it.first<<" "<<it.second<<endl;
                    if(it.second!=k){
                        flag = 1;
                        break;
                    }
                }
                cout<<"?????"<<endl;
                if(flag==0)
                    ans = max(ans,j-i+1);
                cout<<"ans"<<" "<<ans<<endl;
            }
            cout<<"-----"<<endl;
            mp.clear();
        }
        return ans;
    }
}; //solve by debugging

// submitted solution

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        unordered_map<char,int>mp;

        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                int k = mp[s[j]];
                int flag = 0;
                for(auto it:mp){
                    if(it.second!=k){
                        flag = 1;
                        break;
                    }
                }

                if(flag==0)
                    ans = max(ans,j-i+1);
            }
            mp.clear();
        }
        return ans;
    }
};


//without map

class Solution {
public:

    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();

        int maxL = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                //i..j
                if(checkBalanced(freq)) {
                    maxL = max(maxL, j-i+1);
                }
            }
        }

        return maxL;
    }
};
