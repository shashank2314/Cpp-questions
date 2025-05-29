// this case time complexity is O(NLOGN + MLOGM) brute force but it gives Tle on leetcode

class Solution {
public:
    pair<int,int> dfs(int i,unordered_map<int,list<int>> &adj,int parent,map<pair<int,int>,int> &oddstore,map<pair<int,int>,int> &evenstore){
        if(oddstore.find({i,parent+1})!=oddstore.end()){
            return { oddstore[{i,parent+1}],evenstore[{i,parent+1}]};
        }
        int odd = 0;
        int even = 1;
        for(auto x:adj[i]){
            if(x!=parent){
                pair<int,int> p = dfs(x,adj,i,oddstore,evenstore);
                int o = p.first;
                int e = p.second;
                odd+=e;
                even+=o;
            }
        }
        oddstore[{i,parent+1}] = odd;
        evenstore[{i,parent+1}] = even;
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
        map<pair<int,int>,int> oddstore;
        map<pair<int,int>,int> evenstore;
        for(int i=0;i<=m;i++){
            int odd = dfs(i,adj2,-1,oddstore,evenstore).first;
            int even = dfs(i,adj2,-1,oddstore,evenstore).second;
            oddfrome2 = max(oddfrome2,odd);
            evenfrome2 = max(evenfrome2,even);
        }
        vector<int> ans(n+1,0);
        map<pair<int,int>,int> oddstore2;
        map<pair<int,int>,int> evenstore2;
        if(n==0){
            return {dfs(0,adj1,-1,oddstore2,evenstore2).second,oddfrome2};
        }
        for(int i=0;i<=n;i++){
            ans[i] = (dfs(i,adj1,-1,oddstore2,evenstore2).second) + max(oddfrome2,evenfrome2);
        }
        return ans;
    }
};