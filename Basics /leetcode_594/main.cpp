class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int maxi = 0;
        int indi = 0;
        for(auto x:mp){
            int temp = x.first + 1;
            if(mp.find(temp)!=mp.end()){
                if(maxi<(mp[temp]+x.second)){
                    maxi = mp[temp]+x.second;
                    indi = x.first;
                }
            }
            
        }
        
        return maxi;
        
    }
};