//
// Created by feng on 8/7/15.
//

#include "common.h"


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(n&1)
                ++cnt;
            n = n >> 1;
        }
        return cnt;
    }
};


int main()
{
    cout << Solution().hammingWeight(11);
    return 1;
}