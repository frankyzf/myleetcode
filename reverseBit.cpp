//
// Created by feng on 8/7/15.
//

#include "common.h"


class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t flag = 0x80000000;
        uint32_t val =0;
        for(int i = 0; i < 32; ++i)
        {
            if(n&1)
                val |= flag;
            flag = flag >> 1;
            n = n >> 1;
        }
        return val;
    }
};


int main()
{
    cout << Solution().reverseBits(43261596);
    return 1;
}