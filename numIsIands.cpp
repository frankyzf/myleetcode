#include "common.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        if(m < 1)
            return 0;
        const int n = grid[0].size();
        if(n < 1)
            return 0;
        function<void(int, int)> f = [&grid, m, n, &f](int i, int j){
            if(i < 0 || i > m-1 || j < 0 || j > n-1 ) {
              return;
            }
            if(grid[i][j] != '0'){
                if(i > 0 && grid[i-1][j] == '1'){
                    grid[i-1][j] = '2';
                    f(i-1,j);
                }
                if(i < m-1 && grid[i+1][j] == '1'){
                    grid[i+1][j] = '2';
                    f(i+1,j);
                }
                if(j > 0 && grid[i][j-1] == '1'){
                    grid[i][j-1] = '2';
                    f(i, j-1);
                }

                if(j < n-1 && grid[i][j+1] == '1'){
                    grid[i][j+1] = '2';
                    f(i, j+1);
                }
            }
        };
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                char ch = grid[i][j];
                if(ch == '1'){
                    ++res;
                    f(i,j);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> data = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    cout << Solution().numIslands(data);
    return 1;
}