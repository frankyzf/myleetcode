#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if(size == 0)
            return 0;
        int max = numeric_limits<int>::min();
        vector<int> high(size, max);
        for(int i = size-1; i >= 0; --i){
            if(max < prices[i])
                max = prices[i];
            high[i] = max;
        }

        int profit = 0;
        for(int i = 0; i < size-1; ++i){
            if(profit < (high[i+1] - prices[i]))
                profit = (high[i+1] - prices[i]);
        }
        return profit;
    }
};



int main() {

    return 1;
}