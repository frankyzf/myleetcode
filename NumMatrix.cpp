#include "common.h"
//not checked yet


class NumMatrix {
private:
    using PT = pair<int, int>;
    map<PT, int> m;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0)
            return;
        vector<int> col (matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                col[j] += matrix[i][j];
                PT p{i, j};
                m[p] = accumulate(col.begin(), col.begin()+j+1, 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int leftcorner = 0;
        if(row1 > 0 && col1 > 0){
            leftcorner = m[make_pair(row1-1, col1-1)];
        }
        int upper = 0;
        if(row1 > 0){
            upper = m[make_pair(row1-1, col2)];
        }
        int left = 0;
        if(col1 > 0 ){
            left = m[make_pair(row2, col1-1)];
        }
        int n = m[make_pair(row2, col2)];
        //cout << "leftcorner:" << leftcorner << " upper:" << upper << " left:" << left << " total:" << n << endl;
        return n + leftcorner - upper - left;
    }
};




int main() {
    /*
     * 3,0,1,4,2
     * 5,6,3,2,1
     * 1,2,0,1,5
     * 4,1,0,1,7
     * 1,0,3,0,5
     */
    vector<vector<int>> data {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix num(data);
    cout << num.sumRegion(2,1,4,3) << endl;
    cout << num.sumRegion(1,1,2,2) << endl;
    cout << num.sumRegion(1,2,2,4) << endl;
    return 1;
}