#include "common.h"
//not checked yet

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int ba = numeric_limits<int>::min(); // buy state
        int bb = 0; // sell state
        int bc = 0; // idle state
        for (int i = 0; i < prices.size(); ++i) {
            int a = max(ba, bc-prices[i]);
            int b = ba + prices[i];
            int c = max(bc, bb);
            ba =a; bb = b; bc = c;
        }
        return max(bb, bc);
    }
};


int main() {

    return 1;
}