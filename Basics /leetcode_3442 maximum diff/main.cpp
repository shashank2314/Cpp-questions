class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        int maxi1 = 0;
        int mini2 = 100;
        for(auto x:mp){
            if(x.second%2){   
                maxi1 = max(maxi1,x.second);
            }
            else{
                mini2 = min(mini2,x.second);
            }
        }
        
        return maxi1-mini2;
    }
};