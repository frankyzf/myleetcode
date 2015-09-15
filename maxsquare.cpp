#include "common.h"
//not checked yet
/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if(m == 0)
            return 0;
        const int n = matrix[0].size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ms = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1'){
                    int t = 1;
                    if(i > 0 && dp[i-1][j] > t +1){
                        t = dp[i-1][j]-1;
                    }
                    if(j>0 && dp[i][j-1] > t +1){
                        t = dp[i][j-1] -1;
                    }
                    if(i > 0 && j> 0 && dp[i-1][j-1] > t +1){
                        t = dp[i-1][j-1] -1;
                    }
                    bool flag = true;
                    for(; flag && t < min(m -i, n-j); ++t){
                        for (int ii = i; flag && ii <= i+t; ++ii) {
                            if(matrix[ii][j+t] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int jj = j;  flag&& jj <= j + t; ++jj) {
                            if (matrix[i + t][jj] == '0') {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag == false)
                        --t;
                    dp[i][j] = t;
                    ms = ms < t? t: ms;
                }
            }
        }
        return ms*ms;
    }
};


int main() {
    vector<vector<char>> data = { {'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    //vector<vector<char>> data = { {'1'}};
    cout << Solution().maximalSquare(data);
    return 1;
}