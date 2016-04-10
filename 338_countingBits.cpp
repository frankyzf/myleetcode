//
// Created by tjuzf_000 on 4/10/2016.
//
#include "common.h"

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int count = 0;
        res.push_back(count);
        for (int i = 1; i <= num; ++i) {
            int pn = i-1;
            unsigned int mask = 0x01;
            while(mask & pn) {
                mask <<= 1;
                --count;
            }
            res.push_back(++count);
        }
        return res;
    }
};

int main(){
    auto res = Solution().countBits(5);
    for(auto n: res)
        cout << n << ", " ;
    cout << endl;
    return 1;
}