class Solution {
public:
int MOD = 1e9 + 7;
    void getAllString(vector<string> &allstring,int &m,int i,string curr){
        if(i==m){
            allstring.push_back(curr);
            return ;
        }
        char prev = i>0 ? curr[i-1] : ' ';
        int ans = 0;
        if(prev !='R'){
            getAllString(allstring,m,i+1,curr+'R');
        }
        if(prev !='G'){
            getAllString(allstring,m,i+1,curr+'G');
        }
        if(prev != 'B'){
            getAllString(allstring,m,i+1,curr+'B');
        }
        
    }
    int solve(vector<string>& allstring,int i,int n,vector<vector<int>> &dp){
        if(n==0){
            return 1;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int ans = 0;
        for(int k=0;k<allstring.size();k++){
            bool check = true;
            for(int j=0;j<allstring[i].size();j++){
                if(allstring[i][j]==allstring[k][j]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans+=solve(allstring,k,n-1,dp);
                ans%=MOD;
            }
        }
        return dp[i][n] = ans;
    }
    int numOfWays(int n) {
        int m = 3;
        vector<string> allstring;
        string curr = "";
        getAllString(allstring,m,0,curr);
        int ans = 0;
        vector<vector<int>> dp(allstring.size(),vector<int>(n,-1));
        for(int i=0;i<allstring.size();i++){
            ans+=solve(allstring,i,n-1,dp);
            ans%=MOD;
        }
        return ans;
    }
};