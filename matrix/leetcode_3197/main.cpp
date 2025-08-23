class Solution {
public:
    int solvearea(int n1,int n2,int m1,int m2,vector<vector<int>>& grid) {
        for(int i=m1;i<=m2;i++){
            bool check = true;
            for(int j=n1;j<=n2;j++){
                if(grid[j][i]==1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                m1++;
            }
            else{
                break;
            }
        }
        for(int i=m2;i>m1;i--){
            bool check = true;
            for(int j=n1;j<=n2;j++){
                if(grid[j][i]==1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                m2--;
            }
            else{
                break;
            }
        }
        for(int i = n1;i<=n2;i++){
            bool check = true;
            for(int j=m1;j<=m2;j++){
                if(grid[i][j]==1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                n1++;
            }
            else{
                break;
            }
        }
        for(int i=n2;i>n1;i--){
            bool check = true;
            for(int j=m1;j<=m2;j++){
                if(grid[i][j]==1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                n2--;
            }
            else{
                break;
            }
        }
        return (n2-n1+1)*(m2-m1+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int miniarea = m*n;
        // for parallel line int x direction
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int area = 0;
                area+=solvearea(0,i-1,0,m-1,grid);
                area+=solvearea(i,j-1,0,m-1,grid);
                area+=solvearea(j,n-1,0,m-1,grid);
                miniarea = min(miniarea,area);
            }
        }
        // for parallel line int y direction
        for(int i=1;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                int area = 0;
                area+=solvearea(0,n-1,0,i-1,grid);
                area+=solvearea(0,n-1,i,j-1,grid);
                area+=solvearea(0,n-1,j,m-1,grid);
                miniarea = min(miniarea,area);
            }
        }
        // for intersecting lines
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int area1 = 0;
                int area2 = 0;
                int area3 = 0;
                int area4 = 0;
                area1+=solvearea(0,i-1,0,m-1,grid);
                area1+=solvearea(i,n-1,0,j-1,grid);
                area1+=solvearea(i,n-1,j,m-1,grid);
                miniarea = min(miniarea,area1);

                area2+=solvearea(i,n-1,0,m-1,grid);
                area2+=solvearea(0,i-1,0,j-1,grid);
                area2+=solvearea(0,i-1,j,m-1,grid);
                miniarea = min(miniarea,area2);

                area3+=solvearea(0,n-1,0,j-1,grid);
                area3+=solvearea(0,i-1,j,m-1,grid);
                area3+=solvearea(i,n-1,j,m-1,grid);
                miniarea = min(miniarea,area3);

                area4+=solvearea(0,n-1,j,m-1,grid);
                area4+=solvearea(0,i-1,0,j-1,grid);
                area4+=solvearea(i,n-1,0,j-1,grid);
                miniarea = min(miniarea,area4);
            }
        }
        return miniarea;

    }
};