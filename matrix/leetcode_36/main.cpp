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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!validate(i,j,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};