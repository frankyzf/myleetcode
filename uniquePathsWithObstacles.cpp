#include "common.h"
//not checked yet
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int rownum = obstacleGrid.size();
        if(rownum ==0)
            return 0;
        const int colnum = obstacleGrid[0].size();

        vector<vector<int>> nums(rownum, vector<int>(colnum, 0));
        int fb = false;
        for (int i = 0; i < rownum; ++i) {
            if (fb || obstacleGrid[i][0]) {
                fb = true;
                nums[i][0] = 0;
            }
            else{
                nums[i][0] = 1;
            }
        }
        fb = false;
        for (int j = 0; j < colnum; ++j) {
            if (fb || obstacleGrid[0][j]) {
                fb = true;
                nums[0][j] = 0;
            }
            else {
                nums[0][j] = 1;
            }
        }

        for (int i = 1; i < rownum; ++i) {
            for (int j = 1; j < colnum; ++j) {
                if(obstacleGrid[i][j]){
                    nums[i][j] = 0;
                }
                else{
                        nums[i][j] = nums[i-1][j] + nums[i][j-1];
                }
            }
        }
        return nums[rownum-1][colnum-1];
    }
};

int main() {
    vector<vector<int>> data {{0,0}, {0,0}};
    cout << Solution().uniquePathsWithObstacles(data);
    return 1;
}