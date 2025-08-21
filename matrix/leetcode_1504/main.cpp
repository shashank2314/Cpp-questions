class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int res = 0;
        // summation of row rectangles
        for(int i=0;i<n;i++){
            ans[i][0] = mat[i][0];
            res+=ans[i][0];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]){
                    ans[i][j] = 1+ans[i][j-1];
                }
                res+=ans[i][j];
            }
        }
        // summation of col vector
        for(int i=0;i<n-1;i++){
            vector<int> mini(m,0);
            for(int l=0;l<m;l++){
                mini[l] = ans[i][l];
            }
            for(int j=i+1;j<n;j++){
                for(int k=0;k<m;k++){
                    mini[k] = min(mini[k],ans[j][k]);
                    res+=mini[k];
                }
            }
        }
        return res;
    }
};