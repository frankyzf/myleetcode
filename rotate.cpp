#include "common.h"
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix[0].size();
        if(n <= 1)
            return ;
        //symetric along the northeast- southwest line
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n-i; ++j)
                std::swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }


        //symetric along the horizon line
        for(int i = 0; i < n/2; ++i)
        {
            for(int j = 0; j < n; ++j)
                std::swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
};


int main() {

    return 1;
}