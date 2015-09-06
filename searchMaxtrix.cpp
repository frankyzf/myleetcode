//
// Created by feng on 7/26/15.
//

#include "common.h"


class Solution {
public:
    int higherBound(const vector<int>& data, int start, int end, int target)
    {
        if(start >= end - 1)
            return end;
        int mid = start + (end - start)/2;
        if (data[mid] < target)
            return higherBound(data, mid, end, target);
        else
            return higherBound(data, start, mid, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int t = n;
        for(int i = 0; i < m; ++i )
        {
            if(matrix[i][0] > target)
                return false;
            if(matrix[i][n-1] < target)
                continue;
            t = higherBound(matrix[i], 0, t, target);
            //cout << "t:" << t << endl;
            if(( t >= 0 && matrix[i][t] == target) || (t >0 && matrix[i][t-1] == target))
                return true;
        }
        return false;
    }
};


int main()
{
    vector<vector<int> > data ={
            {-5}
    };
    cout << Solution().searchMatrix(data, -5) << endl;
    return 1;

}