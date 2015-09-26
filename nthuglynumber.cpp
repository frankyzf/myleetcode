#include "common.h"
/*
 * Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        if(n<=0)
            throw out_of_range("iput value should > 0");
        if(n ==1)
            return 1;
        res.reserve(n);
        res.push_back(1);
        map<int, int> index{{2,0},{3,0}, {5,0}};
        while(res.size() < n){
            int m = numeric_limits<int>::max();
            for_each(index.begin(), index.end(),
                     [&m, &res](const pair<const int,int>& item) {
                         if (m > res[item.second] * item.first) {
                             m = res[item.second] * item.first;
                         }
                     });
            for_each(index.begin(), index.end(),
                     [&m, &res](pair<const int, int>& item) {
                if(m == res[item.second] * item.first ){
                    item.second++;
                }
            });
            res.push_back(m);
        }
        return res.back();
    }
};

int main() {
    cout << Solution().nthUglyNumber(7);
    return 1;
}