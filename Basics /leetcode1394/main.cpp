class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        int ans = -1;
        for(auto x:mp){
            if(x.first==x.second){
                ans = max(ans,x.first);
            }
        }
        return ans;
    }
};