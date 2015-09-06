#include "common.h"
class Solution {
public:
    double myPow1(double x, int n) {
        if(n == 0)
            return 1;
        else if (n == 1)
            return x;
        else{
            double half = myPow(x, n>>1);
            half *= half;
            if(n&1)
                half *= x;
            return half;
        }
    }
    double myPow(double x, int n) {
        if(n < 0)
            return 1/myPow1(x, -n);
        else
            return myPow1(x, n);
    }
};


int main() {

    return 1;
}