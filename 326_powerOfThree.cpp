//
// Created by tjuzf_000 on 4/10/2016.
//

#include "common.h"



class Solution{
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        else if(n == 1) {
            return true;
        }
        else{
            return n%3 == 0 && this->isPowerOfThree(n/3);
        }
        return false;
    }
};
