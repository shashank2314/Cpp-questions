class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = 0;
        while(k<n){
            int i=k;
            int j=0;
            vector<int> v = {};
            while(i<n && j<n){
                v.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(v.begin(),v.end());
            i=k;
            j=0;
            int m = v.size();
            int z = m-1;
            while(i<n && j<n && z>=0){
                grid[i][j] = v[z];
                i++;
                j++;
                z--;
            }
            k++;
        }
        k = 1 ;
        while(k<n){
            int i=0;
            int j=k;
            vector<int> v = {};
            while(i<n && j<n){
                v.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(v.begin(),v.end());
            i=0;
            j=k;
            int z = 0;
            int m = v.size();
            while(i<n && j<n && z<m){
                grid[i][j] = v[z];
                i++;
                j++;
                z++;
            }
            k++;
        }
        return grid;
    }
};