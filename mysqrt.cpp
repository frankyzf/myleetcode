#include "common.h"
//not checked yet


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int start = 1;
        int end = sqrt(numeric_limits<int>::max());
        while(start < end){
            int mid = (start+end)/2;
            int r = mid*mid;
            if(r < x){
                start = mid+1;
            }
            else if (r > x){
                end = mid-1;
            }
            else
            {
                return mid;
            }
        }
        int mid = (start+end)/2;
        return mid*mid>x?mid-1:mid;

    }
};


int main() {
    cout << Solution().mySqrt(10);
    return 1;
}