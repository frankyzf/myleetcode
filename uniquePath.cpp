#include "common.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        auto f = [](int n){
            double val = 1;
            if(n <= 1)
                return val;
            for(int i =2 ; i <=n; ++i){
                val *= i;
            }
            return val;
        };
        auto f2 = [](int m, int n){
            double val = 1;
            if(m > n)
                return val;
            for(int i =m ; i <=n; ++i){
                val *= i;
            }
            return val;
        };

        auto kk = f2(m, m+n-2)/f(n-1);
        return (int)kk;
    }
};


int main() {

    return 1;
}