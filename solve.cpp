#include "common.h"
//not checked yet
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return ;
        const int rownum = board.size();
        const int colnum = board[0].size();
        vector<vector<bool>> invalid(rownum, vector<bool>(colnum, false));
        stack<pair<int, int>> st;
        for (int i = 0; i < rownum; ++i) {
            for (int j = 0; j < colnum; ++j) {
                if(board[i][j] == 'X' || invalid[i][j] )
                    continue;
                else {
                    vector<vector<bool>> mark(invalid);
                    bool bound = false;
                    st.push(make_pair(i, j));
                    while (!st.empty()) {
                        auto pos = st.top();
                        st.pop();
                        int m = pos.first;
                        int n = pos.second;
                        mark[m][n] = true;
                        if (m == 0 || n == 0 || m == rownum -1 || n == colnum -1 )
                            bound =true;

                        if( n-1>= 0 && mark[m][n-1]== false && board[m][n-1] == 'O'){
                            if(n-1 == 0)
                                bound = true;
                            st.push(make_pair(m, n-1));
                        }
                        if(m-1 >= 0 && mark[m-1][n]== false  && board[m-1][n] == 'O') {
                            if(m-1 == 0)
                                bound = true;
                            st.push(make_pair(m-1, n));
                        }
                        if(n+1 < colnum && mark[m][n+1]== false && board[m][n+1] == 'O') {
                            if(n+1 == colnum -1)
                                bound = true;
                            st.push(make_pair(m, n+1));
                        }
                        if(m+1 < rownum && mark[m+1][n]== false && board[m+1][n] == 'O'){
                            if(m+1 == rownum -1)
                                bound = true;
                            st.push(make_pair(m + 1, n));
                        }
                    }
                    if(bound){
                        invalid.swap(mark);
                    }
                    else{
                        for (int m = 0; m < rownum; ++m) {
                            for (int n = 0; n < colnum; ++n) {
                                if(mark[m][n] && invalid[m][n] == false){
                                    board[m][n] = 'X';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board{{'X','O','O','X','X','X','O','X','O','O'},{'X','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','O','X','X','X','X','X'},{'X','O','X','X','X','O','X','X','X','O'},{'O','X','X','X','O','X','O','X','O','X'},{'X','X','O','X','X','O','O','X','X','X'},{'O','X','X','O','O','X','O','X','X','O'},{'O','X','X','X','X','X','O','X','X','X'},{'X','O','O','X','X','O','X','X','O','O'},{'X','X','X','O','O','X','O','X','X','O'}};
    Solution().solve(board);
    for(auto row: board){
        for(auto ch: row){
            cout << ch;
        }
        cout << endl;
    }
    return 1;
}