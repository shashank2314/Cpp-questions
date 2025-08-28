class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans = {};
        int n = mat.size();
        int m = mat[0].size();
        bool dir = true;
        int k = 0;
        while(k<=(m+n-2)){
            if(dir){
                int i = k;
                int j = 0;
                if(i>=n){
                    i=n-1;
                    j=k-n+1;
                }
                while(i>=0 && j<m){
                    ans.push_back(mat[i][j]);
                    i--;j++;
                }
                dir = !dir;
                k++;
            }
            else{
                int i = 0;
                int j = k;
                if(j>=m){
                    j=m-1;
                    i=k-m+1;
                }
                while(j>=0 && i<n){
                    ans.push_back(mat[i][j]);
                    i++;j--;
                }
                dir = !dir;
                k++;
            }
        }
        return ans;
    }
};