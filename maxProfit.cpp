#include "common.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto findl = [&prices](int i){
            const int size = prices.size();
            while(i+1 < size &&  prices[i+1] < prices[i])
                ++i;
            return i;
        };

        auto findh = [&prices](int i){
            const int size = prices.size();
            while(i+1 < size &&  prices[i+1] >= prices[i])
                ++i;
            return i;
        };

        auto f = [&prices, &findl, &findh](int start, int tend){
            int profit = 0;
            start = findl(start);
            int end = findh(start);
            while(start < tend){
                profit += (prices[end] - prices[start]);
                start = findl(end+1);
                end = findh(start);
            }
            return profit;
        };

        return f(0, prices.size());
    }
};



int main() {

    return 1;
}