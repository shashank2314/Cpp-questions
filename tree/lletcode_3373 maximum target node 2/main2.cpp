// optimised using even odd coloring
class Solution {
public:
    pair<int,int> dfs(int i,unordered_map<int,list<int>> &adj,int parent){

        int odd = 0;
        int even = 1;
        for(auto x:adj[i]){
            if(x!=parent){
                pair<int,int> p = dfs(x,adj,i);
                int o = p.first;
                int e = p.second;
                odd+=e;
                even+=o;
            }
        }
        return {odd,even};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int oddfrome2 = 0;
        int evenfrome2 = 0;
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int,list<int>> adj1;
        unordered_map<int,list<int>> adj2;
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
        oddfrome2 = dfs(0,adj2,-1).first;
        evenfrome2 = dfs(0,adj2,-1).second;
        
        vector<int> ans(n+1,-1);
        if(n==0){
            return {dfs(0,adj1,-1).second,oddfrome2};
        }
        pair<int,int> p = dfs(0,adj1,-1);
        int odd = p.first;
        int even = p.second;
        queue<pair<int,bool>> q;
        q.push({0,true});
        while(!q.empty()){
            int node = q.front().first;
            bool evenbool = q.front().second;
            q.pop();
            if(evenbool){
                ans[node] = even + max(evenfrome2,oddfrome2);
            }
            else{
                ans[node] = odd + max(evenfrome2,oddfrome2);
            }
            for(auto x:adj1[node]){
                if(ans[x]==-1){
                    q.push({x,!evenbool});
                }
            }
        }
        return ans;
    }
};