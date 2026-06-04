class Solution {
    int m, n;
    
    set<pair<int, int>> find(vector<vector<int>>& board) {
        set<pair<int, int>> crushed;
        // Vertical scan (skip top/bottom rows for bounds safety)
        for (int r = 1; r < m - 1; ++r)
            for (int c = 0; c < n; ++c)
                if (board[r][c] && board[r][c] == board[r-1][c] && board[r][c] == board[r+1][c]) {
                    crushed.insert({r-1, c}); crushed.insert({r, c}); crushed.insert({r+1, c});
                }
        // Horizontal scan (skip left/right columns)
        for (int r = 0; r < m; ++r)
            for (int c = 1; c < n - 1; ++c)
                if (board[r][c] && board[r][c] == board[r][c-1] && board[r][c] == board[r][c+1]) {
                    crushed.insert({r, c-1}); crushed.insert({r, c}); crushed.insert({r, c+1});
                }
        return crushed;
    }
    
    void crush(vector<vector<int>>& board, set<pair<int, int>>& crushed) {
        for (auto& [r, c] : crushed) board[r][c] = 0;
    }
    
    void drop(vector<vector<int>>& board) {
        for (int c = 0; c < n; ++c) {
            int lowestZero = -1;
            for (int r = m - 1; r >= 0; --r) {
                if (board[r][c] == 0) 
                    lowestZero = max(lowestZero, r);
                else if (lowestZero != -1) {
                    swap(board[r][c], board[lowestZero][c]);
                    --lowestZero;
                }
            }
        }
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        auto crushed = find(board);
        while (!crushed.empty()) {
            crush(board, crushed);
            drop(board);
            crushed = find(board);
        }
        return board;
    }
};