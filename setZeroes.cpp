#include "common.h"
//not checked yet


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t rowsize = matrix.size();
        if(rowsize == 0)
            return;
        const size_t colsize = matrix[0].size();
        if(colsize == 0)
            return;
        bool bfirstrow = false, bfirstcol = false;
        for (int i = 0; i < rowsize; ++i) {
            if (matrix[i][0] == 0) {
                bfirstcol = true;
                break;
            }
        }
        for (int j = 0; j < colsize; ++j) {
            if(matrix[0][j] == 0) {
                bfirstrow = true;
                break;
            }
        }
        
        for (int i = 0; i < rowsize; ++i) {
            for (int j = 0; j < colsize; ++j) {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rowsize; ++i) {
            if(matrix[i][0] == 0){
                for (int j = 1; j < colsize; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < colsize; ++j) {
            if(matrix[0][j] == 0){
                for (int i = 1; i < rowsize; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(bfirstcol){
            for (int i = 0; i < rowsize; ++i) {
                matrix[i][0] = 0;
            }
        }
        if(bfirstrow){
            for (int j = 0; j < colsize; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};


int main() {

    return 1;
}