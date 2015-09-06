//
// Created by feng on 8/23/15.
//

#include "common.h"

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.size() == 0 || words.size() == 0){
            return res;
        }
        auto fc = [&words](char c, int len, vector<int>& v){
            int vi = 0;
            if(v.size() == 0)
                return false;
            int size = v.size() -1;
            while(vi <= size-1){
                if(words[v[vi]][len] != c){
                    v[vi] = v[size--];
                }
                else
                    ++vi;
            }
            if(size == 0) {
                v.resize(0);
                return false;
            }
            else {
                v.resize(size + 1);
                return true;
            }
        };

        function<bool(int, int, int, vector<int>&, vector<vector<bool>>&)> f =
                [&board, &words,&res, &f, &fc] (int i, int j, int len, vector<int> candindex, vector<vector<bool>>& flag){
                    if( fc(board[i][j], len, candindex)){
                        ++len;
                        flag[i][j] = true;
                        transform(candindex.begin(), candindex.end(), back_inserter(res),
                                  [&res, words, len](int i){
                                     if(words[i].length() == len)
                                        return words[i];}
                        );
                        if(i < board.size() -1 && flag[i+1][j] == false) {
                            f(i+1, j, len, candindex, flag);
                        }
                        if (j < board[0].size() - 1 && flag[i][j+1] == false) {
                            f(i, j + 1, len, candindex, flag);
                        }
                        if(i > 0 && flag[i-1][j] == false) {
                            f(i - 1, j, len, candindex, flag);
                        }
                        if(j > 0 && flag[i][j-1] == false){
                            f(i, j-1, len, candindex, flag);
                        }
                        return true;
                    }
                    return false;
                };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
                vector<int> v(words.size(), 0);
                int n = 0;
                for_each(v.begin(), v.end(), [&n](int& vi){vi = n++;});
                f(0, 0, 0, v, flag);
            }
        }
        return res;

    }
};


int main(){
    vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'} };
    vector<string> words = {"oath","pea","eat","rain"};
    auto r = Solution().findWords(board, words);
    for(auto w: r) {
        cout << w << ",";
    }
        cout << endl;

    return 1;
}