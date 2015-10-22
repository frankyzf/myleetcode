#include "common.h"
//not checked yet
class Solution {
private:
    using ST = unordered_set<char>;
    using VT = vector<char>;


    void printvv (int i, int j, const vector<VT>& board){
        /*cout << "==> level:" << i << ", " << j << endl;
        for(auto col: board){
            for(auto n: col)
                cout << n << "  ";
            cout << endl;
        }
         */
    };







public:
    void solveSudoku(vector<vector<char>>& board) {
        auto cboard = board;

        auto judgcell =[&board, this](int i, int j)->bool{
            vector<bool> flag(9, false);
            for(int m = 0; m <9; ++m){
                if(board[m][j] != '.') {
                    int index = board[m][j] - '1';
                    if (flag[index])
                        return false;
                    flag[index] = true;
                }
            }
            fill(flag.begin(), flag.end(), false);
            for(int n = 0; n < 9; ++n){
                if(board[i][n] != '.'){
                    int index = board[i][n] - '1';
                    if(flag[index] )
                        return false;
                    flag[index] = true;
                }
            }
            fill(flag.begin(), flag.end(), false);
            for(int m = i/3*3; m < i/3*3+3 ; ++m){
                for(int n = j/3*3; n < j/3*3+3 ; ++n){
                    if(board[m][n] != '.') {
                        int index = board[m][n] - '1';
                        if (flag[index])
                            return false;
                        flag[index] = true;
                    }
                }
            }
            return true;
        };


        function<bool(int, int)> f = [&f, &judgcell, &board, &cboard, this](int i, int j ){
            if(i == 9){
                return true;
            }
            printvv(i, j, board);
            if(cboard[i][j] != '.'){
                if(j == 8)
                    return f(i+1, 0);
                else
                    return f(i, j+1);
            }
            char k = '1';
            do {
                board[i][j] = k;
                if(judgcell(i, j)){
                    if(j == 8 ){
                        if(f(i+1, 0))
                            return true;
                    }
                    else{
                        if(f(i, j+1))
                            return true;
                    }
                }
                ++k;
            }while( k <= '9');
            board[i][j] = cboard[i][j];
            return false;
        };

        f(0, 0);

    }
};

int main() {
    vector<vector<char>> board{{'.','.','9','7','4','8','.','.','.'},
                               {'7','.','.','.','.','.','.','.','.'},
                               {'.','2','.','1','.','9','.','.','.'},
                               {'.','.','7','.','.','.','2','4','.'},
                               {'.','6','4','.','1','.','5','9','.'},
                               {'.','9','8','.','.','.','3','.','.'},
                               {'.','.','.','8','.','3','.','2','.'},
                               {'.','.','.','.','.','.','.','.','6'},
                               {'.','.','.','2','7','5','9','.','.'}};
    Solution().solveSudoku(board);
    for(auto col: board){
        for(auto i: col)
            cout << i << "  ";
        cout << endl;
    }
    return 1;
}