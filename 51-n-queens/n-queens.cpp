class Solution {
public:
    unordered_set<int> col, posdiag, negdiag;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(0,n,board);
        return res; 
    }

private: 
    void backtrack(int r, int n ,vector<string>& board){
    if(r == n){
         res.push_back(board); 
         return;
    }

    for(int c = 0 ; c < n; c++){
        if(col.count(c) || posdiag.count(r+c) || negdiag.count(r-c)) {      continue;}
    
    col.insert(c);
    posdiag.insert(r+c);
    negdiag.insert(r-c);
    board[r][c]='Q';

    backtrack(r+1,n,board);

    col.erase(c);
    posdiag.erase(r+c);
    negdiag.erase(r-c);
    board[r][c]='.';
    
  }
 }
};