#include "common.h"
//not checked yet
class Solution {
private:
    struct cell{
        int i ;
        int j ;
        int h ;
        constexpr cell(int i_=0, int j_=0, int h_=0):i(i_), j(j_), h(h_){}
    };

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int rowsize = matrix.size();
        if(rowsize == 0)
            return 0;
        const int colsize = matrix[0].size();
        if(colsize == 0)
            return 0;
        int maxarea = 0;
        vector<vector<cell>> vv(rowsize, vector<cell>(colsize, cell(0, colsize, 0)));
        for (int i = 0; i < rowsize; ++i) {
            int start = 0, end = colsize;
            for (int j = 0; j < colsize; ++j) {
                if(matrix[i][j] == '0'){
                    start = j+1;
                }
                else{
                    int h = 1;
                    int left = start;
                    if(i !=0){
                        h = vv[i-1][j].h +1;
                        left = max(left, vv[i-1][j].i);
                    }
                    vv[i][j]= cell(left, 0, h );
                }
            }
            for (int j = colsize-1; j >= 0; --j) {
                if(matrix[i][j] == '0'){
                    end = j;
                }
                else{
                    int right = end;
                    if(i != 0){
                        right = min(right, vv[i-1][j].j);
                    }
                    vv[i][j].j = right;
                }
            }
            for (int j = 0; j < colsize; ++j) {
                maxarea = max(maxarea, (vv[i][j].j - vv[i][j].i)*vv[i][j].h );
            }
        }

        return maxarea;

    }
};

int main() {
    vector<vector<char>> data {{'0','0', '0', '0'}, {'0','0', '0', '1'} , {'1','1', '1', '1'}};
    cout << Solution().maximalRectangle(data);
    return 1;
}