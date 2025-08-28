class Solution {
public:
    int solve(int i,int j,int &n,int &m,vector<vector<int>>& grid,bool turn,int dir,int prev,vector<vector<vector<vector<int>>>> &dp){
        if(i>=n || j>=m || i<0 || j<0){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(grid[i][j]==prev){
            return 0;
        }
        if(dp[i][j][turn][dir]!=-1){
            return dp[i][j][turn][dir];
        }
        int ans = 0;
        if(turn){
            if(dir==0){
                ans = max(ans,1+solve(i+1,j+1,n,m,grid,turn,dir,grid[i][j],dp));
            }
            else if(dir==1){
                ans = max(ans,1+solve(i+1,j-1,n,m,grid,turn,dir,grid[i][j],dp));
            }
            else if(dir==2){
                ans = max(ans,1+solve(i-1,j-1,n,m,grid,turn,dir,grid[i][j],dp));
            }
            else if(dir==3){
                ans = max(ans,1+solve(i-1,j+1,n,m,grid,turn,dir,grid[i][j],dp));
            }
        }
        else{
                if(dir==0){
                    ans = max(ans,1+solve(i+1,j+1,n,m,grid,turn,dir,grid[i][j],dp));
                    ans = max(ans,1+solve(i+1,j-1,n,m,grid,true,1,grid[i][j],dp));
                }
                else if(dir==1){
                    ans = max(ans,1+solve(i+1,j-1,n,m,grid,turn,dir,grid[i][j],dp));
                    ans = max(ans,1+solve(i-1,j-1,n,m,grid,true,2,grid[i][j],dp));
                }
                else if(dir==2){
                    ans = max(ans,1+solve(i-1,j-1,n,m,grid,turn,dir,grid[i][j],dp));
                    ans = max(ans,1+solve(i-1,j+1,n,m,grid,true,3,grid[i][j],dp));
                }
                else if(dir==3){
                    ans = max(ans,1+solve(i-1,j+1,n,m,grid,turn,dir,grid[i][j],dp));
                    ans = max(ans,1+solve(i+1,j+1,n,m,grid,true,0,grid[i][j],dp));
                }
            
        }
        return dp[i][j][turn][dir] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(2,vector<int>(4,-1))));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && ans<max(n,m)){
                    
                    bool turn  = false;
                    int dir = -1;
                    ans = max(ans,1+solve(i+1,j+1,n,m,grid,turn,0,0,dp));
                    ans = max(ans,1+solve(i+1,j-1,n,m,grid,turn,1,0,dp));
                    ans = max(ans,1+solve(i-1,j-1,n,m,grid,turn,2,0,dp));
                    ans = max(ans,1+solve(i-1,j+1,n,m,grid,turn,3,0,dp));
                }
            }
        }
        return ans;
    }
};