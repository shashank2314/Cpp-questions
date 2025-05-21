class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n,false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        vector<int> a(n,0);
        for (int i = 0; i < m; i++) {
            if(row[i])
                matrix[i] = a;
        }
        for(int j=0;j<n;j++){
            if(col[j]){
                for(int i=0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};