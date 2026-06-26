class Solution {
    bool dfs(vector<vector<char>>&board, string word, int row, int col, int idx){

        if(idx==word.size())return true;//base case
        //pruning conditions
        if(row>=board.size()||row<0||col>=board[0].size()||col<0)return false;
        if(board[row][col]!=word[idx])return false; //match nahi kiya
        if(board[row][col]=='#')return false; //already visited to vapis nahi kar sakte

        char temp = board[row][col];
        board[row][col]= '#';

        bool found = dfs(board, word, row+1, col, idx+1)||
                     dfs(board, word, row-1, col, idx+1)||
                     dfs(board, word, row, col+1, idx+1)||
                     dfs(board, word, row, col-1, idx+1);
        
        board[row][col]= temp;
        return found;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(dfs(board, word, r, c, 0))return true;
            }
        }
        return false;
    }
};
