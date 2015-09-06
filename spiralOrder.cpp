//
// Created by feng on 8/17/15.
//

#include "common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        auto f = [&matrix, &res](int i, int j, int m, int n){
            for(int k = j; k <=n; ++k )
                res.push_back(matrix[i][k]);
            for(int k = i +1; k <= m; ++k)
                res.push_back(matrix[k][n]);
            for(int k = n-1; k >= j; --k)
                res.push_back(matrix[m][k]);
            for(int k = m-1; k > i; --k)
                res.push_back(matrix[k][j]);
        };

        int i = 0, j = 0, m = matrix.size()-1, n = matrix[0].size()-1;
        while(i < m && j < n){
            f(i, j, m, n);
            ++i;
            ++j;
            --m;
            --n;
        }
        if(i == m){
            for(int k = j; k <= n; ++k)
                res.push_back(matrix[i][k]);
        }
        else if(j == n){
            for(int k = i; k <= m; ++k){
                res.push_back(matrix[k][j]);
            }
        }
        return res;
    }
};


int main(){
    vector<vector<int>> data { {2,3} };
    auto r = Solution().spiralOrder(data);
    for(auto v: r)
        cout << v << ",";
    cout << endl;
    return 1;
}