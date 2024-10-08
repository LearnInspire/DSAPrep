/*  Time complexity for Approach-1 : O(N!)
    Unlike the brute force approach, we will only place queens on squares that
aren't under attack. For the first queen, we have N options. For the next queen,
we won't attempt to place it in the same column as the first queen, and there
must be at least one square attacked diagonally by the first queen as well.
Thus, the maximum number of squares we can consider for the second queen is
    (N−2). For the third queen, we won't attempt to place it in 2 columns
already occupied by the first 2 queens, and there must be at least two squares
attacked diagonally from the first 2 queens. Thus, the maximum number of squares
we can consider for the third queen is (N-4). This pattern continues, resulting
in an approximate time complexity of O(N!)
//Approach-1 (Simple dfs)
//T.C : O(N!) - Read the reason above
//S.C : O(N) to store the result
*/
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string>& board, int row, int col) {
        // look for up
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // check left diagonal upwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // check right diagonal upwards
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void solve(vector<string>& board, int row) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        
        /*
            place one queen at every row and check before placing
            in every directions where there is risk if being attackes
            i.e. up, diagonally because we are placing queens from
            top row to bottom row, so we need to check if we put a queen
            vertically up in some row or diagonally upwards in some row
        */
        for(int i = 0; i<board.size(); i++) {
            if(isValid(board, row, i)) {
                board[row][i] = 'Q';
                
                solve(board, row+1);
                
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));
        // For, n = 3, board = {"...", "...", "..."} initially

        solve(board, 0);

        return result;
    }
};