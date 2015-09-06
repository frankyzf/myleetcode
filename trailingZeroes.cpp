//
// Created by feng on 8/11/15.
//

#include "common.h"

class Solution {
public:
    int trailingZeroes(int n) {
        if(n ==0)
            return 0;
        else if (n < 0)
            n *=-1;

        int l = 9;
        int r = 0;
        while(l > r)
        {
            int mid = (l+r)/2+1;
            if(n%(int)pow(10, mid)){
                l = mid -1;
            }else
            {
                r = mid;
            }
        }
        return l;
    }
};

int main(){
    cout << Solution().trailingZeroes(100);
    return 1;
}