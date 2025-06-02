class Solution {
public:
// basic approaches only
    int solve(vector<int>& ratings,int i,vector<int>& dp){
        if(i>=ratings.size() || i<0){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int n = ratings.size();
        if(i-1>=0 && i+1<n && ratings[i]<=ratings[i+1] && ratings[i]<=ratings[i-1]){
            return dp[i] = 1;
        }
        else if(i-1>=0 && i+1<n && ratings[i]>ratings[i+1] && ratings[i]>ratings[i-1]){
            return dp[i] = 1 + max(solve(ratings,i-1,dp),solve(ratings,i+1,dp));
        }
        else if(i-1>=0 && ratings[i]>ratings[i-1]){
            return dp[i] = 1 + solve(ratings,i-1,dp);
        }
        else if( i+1<n && ratings[i]>ratings[i+1]){
            return dp[i] = 1 + solve(ratings,i+1,dp);
        }
        return dp[i] = 1;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(ratings.size(),-1);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=solve(ratings,i,dp);
        }
        return ans;
    }
};