#include "common.h"
class Solution {
public:

    int minPathSum(vector<vector<int> > &grid) {

        const int m = grid.size();
        const int n = grid.begin()->size();
        vector<vector<int> > cost = vector<vector<int> >(m, vector<int>(n, 0));

        cost[0][0] = grid[0][0];
        for(int j = 1; j < n; ++j)
            cost[0][j] = cost[0][j-1] + grid[0][j];
        for(int i = 1; i < m; ++i)
            cost[i][0] = cost[i-1][0] + grid[i][0];

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j< n; ++j)
            {
                cost[i][j] = std::min(cost[i-1][j], cost[i][j-1]) + grid[i][j];
            }
        }
        return cost[m-1][n-1];
    }


};


int main() {

    return 1;
}