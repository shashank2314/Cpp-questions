class Solution {
public:
    bool validate(int i,int j,vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            if( j!=k && board[i][j]==board[i][k]){
                return false;
            }
            if(i!=k && board[i][j]==board[k][j]){
                return false;
            }
        }
        int row = i/3;
        int col = j/3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if((row*3 + k!=i || col*3 + l!=j) && board[row*3 + k][col*3 + l]==board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(int i,int j,vector<vector<char>>& board,bool &check){
        if(i==9){
            check = true;
            return;
        }
        if(check){
            return;
        }
        if(board[i][j]=='.'){
            for(int k=1;k<=9;k++){
                board[i][j] = '0'+k;
                if(validate(i,j,board)){
                    if(j!=8){
                        solve(i,j+1,board,check);
                    }
                    else{
                        solve(i+1,0,board,check);
                    }
                    if(check){
                        return;
                    }
                }
                board[i][j] = '.';
            }
        }
        else{
            if(j!=8){
                solve(i,j+1,board,check);
            }
            else{
                solve(i+1,0,board,check);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int i=0;
        int j=0;
        bool check = false;
        solve(i,j,board,check);
    }
};