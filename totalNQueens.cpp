//
// Created by feng on 8/14/15.
//

#include "common.h"

class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        if(n == 0) {
            return cnt;
        }
        vector<int> seq(n, 0);
        int index = 0;
        for_each(seq.begin(), seq.end(), [&index](int &m) { m = index++; });
        do {
            for (int i = 0;    i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (abs(j - i) == abs(seq[i] - seq[j])) {
                        break;
                    }
                }
            }
            ++cnt;
        } while (next_permutation(seq.begin(), seq.end()));
        return cnt;
    }
};


int main(){
    cout << Solution().totalNQueens(8);
    return 1;
}