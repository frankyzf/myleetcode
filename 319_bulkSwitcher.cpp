//
// Created by tjuzf_000 on 4/10/2016.
//

#include "common.h"


class Solution {
public:
    int bulbSwitch(int n) {
        int base =1;
        int square = 1;
        int cnt  = 0;
        for (int i = 1; i <= n; ++i) {
            while(square < i){
                ++base;
                square = base*base;
            }

            if(square  == i) {
                ++cnt;
            }
            else{
                continue;
            }
        }
        return cnt;
    }
};

