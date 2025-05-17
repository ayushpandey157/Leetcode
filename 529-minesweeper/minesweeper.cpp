class Solution {
public:
    int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // we do bfs continuously
        // when we come near bomb, we do bfs from bomb within 1 degree of neighbors

        // edge case if click is bomb - mark it X and return board
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }

        // do bfs
        bfs(board,click[0],click[1]);
        return board;
    }

    void bfs(vector<vector<char>>& board, int r, int c){
        queue<pair<int,int>> qu;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        // add to qu and visited
        qu.push({r,c});
        visited[r][c] = true;
        while(!qu.empty()){
            // pop from qu
            auto [qr,qc] = qu.front();
            qu.pop();
            // ** create temp valid neighbors
            vector<pair<int,int>> valid_neighbors;
            // ** create count to see if cell is near bomb, how many bombs?
            int count = 0;
            for(const auto& [dr,dc]:dir){
                int nr = qr+dr, nc = qc+dc;
                if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size()){
                   // if any of the eight neighbors has a bomb increment the count
                   if(board[nr][nc]=='M'){
                        count++;
                   }
                   // if neighbor = E, it might be valid candidate
                   else if(board[nr][nc] == 'E'){
                        valid_neighbors.push_back({nr,nc});
                   }
                }
            }
            // if count is 0 i.e. cell is not near bomb
            if(count == 0){
                // make it B i.e. update the state
                board[qr][qc] = 'B'; 
                // for all valid neighbor add to qu and visited
                for(const auto& [nr,nc]:valid_neighbors){
                    if(!visited[nr][nc]){
                        qu.push({nr,nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            else{
                // update the cell to total bombs count near it
                board[qr][qc] = count + '0';
            }
        }
        
    }
};