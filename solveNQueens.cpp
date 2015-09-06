//
// Created by feng on 8/14/15.
//

#include "common.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> seq(n, 0);
        vector<vector<string>> res;
        if (n == 0) {
            return res;
        }
        int index = 0;
        for_each(seq.begin(), seq.end(), [&index](int &i) { i = index++; });
        do {
            bool valid  = true;
            for (int i = 0; i < n; ++i) {
                for(int j = i+1; j < n; ++j) {
                    if (abs(j - i) == abs(seq[i] - seq[j])) {
                        valid = false;
                        break;
                    }

                }
            }
            if(valid ) {
                vector<string> r;

                for(int i = 0; i < n; ++i) {
                    string s;
                    fill_n(back_inserter(s), n, '.');
                    s[seq[i]] = 'Q';
                    r.push_back(s);
                }
                res.push_back(move(r));
            }
        } while (next_permutation(seq.begin(), seq.end()));
        return res;
    }
};


int main(){
    auto r = Solution().solveNQueens(4);
    for(auto v: r) {
        for (auto s: v) {
            cout << s << endl ;
        }
        cout << endl;
    }
    return 1;
}