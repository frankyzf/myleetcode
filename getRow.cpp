//
// Created by feng on 8/7/15.
//

#include "common.h"


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0 )
            return vector<int>{};
        else if (rowIndex == 0)
            return vector<int>{1};
        else if (rowIndex == 1)
            return vector<int>{1,1};
        vector<int> prev;
        vector<int> p= vector<int>{1, 1};
        for(int i = 2; i<= rowIndex; ++i){
            swap(prev, p);
            p.clear();
            p.push_back(1);
            for(int j = 1; j < i; ++j){
                p.push_back(prev[j-1]+prev[j]);
            }
            p.push_back(1);
        }
        return p;
    }
};


int main(){

    auto r = Solution().getRow(3);
    for(auto v: r)
        cout << v << ",";
    cout << endl;
    return 1;
}