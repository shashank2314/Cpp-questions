class Solution {
public:
    int dfs(int node,unordered_map<int,list<int>> &adj,int parent,int k){
        // for leaf nodes
        if(k==0) return 1;
        // for current node
        int ans = 1;
        for(auto i: adj[node]){
            // check prev node
            if(i!=parent){
                ans+=dfs(i,adj,node,k-1);
            }
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        
        unordered_map<int,list<int>> adj1;
        unordered_map<int,list<int>> adj2;
        int n = edges1.size();
        int m = edges2.size();
        if(k==0){
            vector<int> ans(n+1,1);
            return ans;
        }
        for(auto e:edges1){
            int a = e[0];
            int b = e[1];
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for(auto e:edges2){
            int a = e[0];
            int b = e[1];
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        int maxi = 1;
        if(k>1){
            for(int i=0;i<=m;i++){
                maxi = max(maxi,dfs(i,adj2,-1,k-1));
            }
        }
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i] = dfs(i,adj1,-1,k)+maxi;
        }
        return ans;
    }
};