//
// Created by feng on 8/18/15.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n1) {
        if(n1 == 0){
            return vector<vector<int>> {};
        }
        vector<vector<int>> res(n1, vector<int>(n1, 0));
        int sn = 0;
        auto f = [&res, &sn](int m, int n, int k, int l){
            for(int j = n; j <=l; ++j)
                res[m][j] = ++sn;
            for(int i = m+1; i <= k; ++i)
                res[i][l] = ++sn;
            for(int j = l -1; j >= n; --j )
                res[k][j] = ++sn;
            for(int i = k-1; i >= n+1; --i)
                res[i][n] = ++sn;

        };
        int m = 0, n = 0, k = n1-1, l = n1-1;
        while(m < k){
            f(m, n, k, l);
            ++m; ++n; --k; --l;
        }
        if(n1&1){
            res[n1>>1][n1>>1] = ++sn;
        }
        return res;
    }
};


int main(){
    auto r = Solution().generateMatrix(3);
    for(auto v: r){
        for(auto i: v){
            cout << i << ",";
        }
        cout << endl;
    }
    return 1;
}