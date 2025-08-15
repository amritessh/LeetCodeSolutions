class Solution {
public:
    int count = 0;
    unordered_set<int> col, posdiag, negdiag;
    vector<vector<string>> res;
    int totalNQueens(int n) {
        // vector<string> board(n,string(n,'.'));
        return backtrack(0,n);

    }

private: 
    int  backtrack(int r, int n ){
    if(r == n){
        //  res.push_back(board); 
        //  count++;
         return 1;
    }

    int count = 0;
    for(int c = 0 ; c < n; c++){
        if(col.count(c) || posdiag.count(r+c) || negdiag.count(r-c)) {      continue;}
    
    col.insert(c);
    posdiag.insert(r+c);
    negdiag.insert(r-c);
    // board[r][c]='Q';

    count+=backtrack(r+1,n);

    col.erase(c);
    posdiag.erase(r+c);
    negdiag.erase(r-c);
    // board[r][c]='.';
    
  }
  return count;
 }
};