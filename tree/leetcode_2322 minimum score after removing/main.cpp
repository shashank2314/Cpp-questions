class Solution {
public:
    void dfs(int node,int parent,vector<int> &nums,unordered_map<int,list<int>> &adj,vector<int> &xor_cal,vector<unordered_set<int>>& decendant){
        xor_cal[node] = nums[node];
        decendant[node].insert(node);
        for(auto x:adj[node]){
            if(x!=parent){
                dfs(x,node,nums,adj,xor_cal,decendant);
                xor_cal[node] = xor_cal[node] ^ xor_cal[x];
                decendant[node].insert(decendant[x].begin(),decendant[x].end()); 
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int n = nums.size();
        vector<int> xor_cal(n,0);
        vector<unordered_set<int>> decendant(n,unordered_set<int>());
        dfs(0,-1,nums,adj,xor_cal,decendant);
        int total = xor_cal[0];
        int mini = INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xori = xor_cal[i];
                int xorj = xor_cal[j];
                if(decendant[i].count(j)){
                    mini = min(mini,max({total^xori,xori^xorj,xorj})-min({total^xori,xori^xorj,xorj}));
                }
                else if(decendant[j].count(i)){
                    mini = min(mini,max({total^xorj,xori^xorj,xori})-min({total^xorj,xori^xorj,xori}));
                }
                else{
                    mini = min(mini,max({total^xorj^xori,xorj,xori})-min({total^xorj^xori,xorj,xori}));
                }
            }
        }
        return mini;
    }
};