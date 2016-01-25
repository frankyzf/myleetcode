//
// Created by feng on 8/10/15.
//

#include "common.h"


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       const int size = board.size();
       const vector<pair<int, int>> round {make_pair(-1, 0), make_pair(1,0), make_pair(0,-1), make_pair(0, 1)};
       vector<vector<bool>> flag(size, vector<bool>(size, false));

       auto f = [&flag, &board, &word, &round, size](int i, int j, char ch, int n){
           auto v = round[n];
           int ni = i + v.first;
           int nj = j+ v.second;
           if(ni >= 0 && ni < size && nj >=0 && nj < size && board[ni][nj] == ch)
                return true;
           return false;
       };

        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                for(auto& fg: flag)
                    fg.assign( size, false );
                if(word[0] == board[i][j]){
                    stack<tuple<int, int, int>> st;
                    st.push(make_tuple(i, j, 1));
                    int pi, pj, si;
                    while(!st.empty()){
                        tie(pi, pj, si) = st.top();
                        st.pop();
                        if(si == word.length())
                            return true;
                        for(int nn = 0; nn < 4; ++nn){
                            if(f(pi, pj, word[si], nn)){
                                st.push(make_tuple(pi+round[nn].first, pi+round[nn].second, si+1));
                            }
                        }
                    }

                }
            }
        }
        return false;
    }
};

int main(){
    return 1;
}