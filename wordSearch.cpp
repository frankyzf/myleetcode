#include "common.h"
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rsize = board.size();
        if(rsize == 0)
            return false;
        const int csize = board[0].size();
        vector<vector<bool>> flags(rsize, vector<bool>(csize, false));
        function<bool (int, int, int) > f = [&flags, &board, &word, csize, rsize, &f](int m, int n, int wi) {
            if (wi >= word.length())
                return true;
            if (m < rsize - 1 && flags[m + 1][n] == false && board[m + 1][n] == word[wi]) {
                flags[m + 1][n] = true;
                if (f(m + 1, n, wi + 1))
                    return true;
                else {
                    flags[m + 1][n] = false;
                }
            }
            if (n < csize - 1 && flags[m][n + 1] == false && board[m][n + 1] == word[wi]) {
                flags[m][n + 1] = true;
                if (f(m, n + 1, wi + 1))
                    return true;
                else {
                    flags[m][n + 1] = false;
                }
            }
            if (m > 0 && flags[m - 1][n] == false && board[m - 1][n] == word[wi]) {
                flags[m - 1][n] = true;
                if (f(m - 1, n, wi + 1))
                    return true;
                else {
                    flags[m - 1][n] = false;
                }
            }
            if (n > 0 && flags[m][n - 1] == false && board[m][n - 1] == word[wi]) {
                flags[m][n - 1] = true;
                if (f(m, n - 1, wi + 1))
                    return true;
                else {
                    flags[m][n - 1] = false;
                }
            }
            return false;
        };


        for(int i = 0; i < rsize; ++i){
            for (int j = 0; j < csize; ++j){
                if(board[i][j] == word[0]) {
                    flags.assign(rsize, vector<bool>(csize, false));
                    flags[i][j] = true;
                    if (f(i, j, 1))
                        return true;
                }
            }
        }
        return false;
    }
};



int main() {

    return 1;
}