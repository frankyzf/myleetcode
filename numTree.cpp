#include "common.h"
//not checked yet


class Solution {
public:
    int numTrees(int n) {
        function<int(int, int)> f = [ &f](int i, int j){
            static map<int, int> mm;
            if(i >= j)
                return 1;
            if(mm.count(j-i))
                return mm[j-i];
            int sum = 0;
            for(int n = i; n <= j; ++n){
                sum += f(i, n-1) * f(n+1, j);
            }
            mm[j-i] = sum;
            return sum;
        };
        return f(0, n-1);
    }
};



int main() {
    cout << Solution().numTrees(19);
    return 1;
}