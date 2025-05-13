class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int live = 0;

                if(i-1 >= 0 && (board[i-1][j] == 1 || board[i-1][j] == 2)) live++; 
                if(i+1 < m && (board[i+1][j] == 1 || board[i+1][j] == 2)) live++; 
                if(j-1 >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 2)) live++; 
                if(j+1 < n && (board[i][j+1] == 1 || board[i][j+1] == 2)) live++; 
                if(i-1 >= 0 && j-1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)) live++; 
                if(i-1 >= 0 && j+1 < n && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2)) live++; 
                if(i+1 < m && j-1 >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 2)) live++; 
                if(i+1 < m && j+1 < n && (board[i+1][j+1] == 1 || board[i+1][j+1] == 2)) live++; 

                if(board[i][j] == 1){
                    if(live < 2 || live > 3) board[i][j] = 2;
                }
                else{
                    if(live == 3) board[i][j] = 3;
                }

            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == 3) board[i][j] = 1;
            }
        }

    }
};