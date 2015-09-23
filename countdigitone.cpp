#include "common.h"
//not checked yet
/*
 * Given an integer n, count the total number of digit 1
 * appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

class Solution {
public:
    int countDigitOne(int n) {
        int highn(n), lowc(1), lown(0);
        int res = 0;
        int c;
        while(highn > 0){
            c = highn%10;
            highn /= 10;
            if(c == 1){
                res += highn*lowc;
                res += (lown+1);
            }
            else if (c == 0){
                res += (highn*lowc);
            }
            else{
                res += (highn+1)*lowc;
            }
            lown = c*lowc + lown;
            lowc *=10;
        }
        return res;
    }
};

int main() {
    cout << Solution().countDigitOne(13) << endl;
    return 1;
}