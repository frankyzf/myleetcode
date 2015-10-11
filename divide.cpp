#include "common.h"
//not checked yet


class Solution {
public:
    int divide(int dividend, int divisor) {
        const int MAXINT = numeric_limits<int>::max();
        const unsigned int MAXUINT = numeric_limits<unsigned int>::max();

        if(divisor == 0)
            return MAXINT;
        if(dividend == 0)
            return 0;
        bool bneg = false;
        if((divisor < 0 && dividend >0)|| (divisor > 0 && dividend < 0))
            bneg = true;
        unsigned int udivisor = divisor < 0 ? (unsigned int)~divisor + 1 : divisor;
        unsigned int udividend = dividend<0?  (unsigned int)~dividend+1 : dividend;
        unsigned  int base = 0;
        unsigned int mul = 0;
        unsigned int addnum = udivisor;
        while(true){
            unsigned  int d = 1;
            while(base <= MAXUINT - addnum && base + addnum < udividend){
                addnum += addnum;
                d+= d;
            }

            if( base <= MAXUINT - addnum && base + addnum == udividend){
                mul += d;
                break;
            }
            else{
                if(d == 1)
                    break;
                else{
                    base += addnum/2;
                    mul += d/2;
                    addnum = udivisor;
                }
            }
        }
        if( (bneg == false && mul  > (unsigned int )MAXINT ) || (bneg == true && mul   > (unsigned int) MAXINT + 1))
            return MAXINT;
        else{
            if(bneg)
                mul = -mul;
            return mul;
        }

    }
};



int main() {
    cout << Solution().divide(1, 1);
    return 1;
}