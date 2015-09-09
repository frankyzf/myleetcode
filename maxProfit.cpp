#include "common.h"
//not checked yet
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> hv;
        int h = numeric_limits<int>::min();
        for (int i = prices.size() - 1; i >= 0; --i) {
            if (h < prices[i]) {
                h = prices[i];
            }
            hv.push_back(h);
        }
        reverse(hv.begin(), hv.end());
        int res = numeric_limits<int>::min();
        for(int i = 0; i < prices.size() -1; ++i){
            if (res < hv[i+1] - prices[i]){
                res = hv[i+1] - prices[i];
            }
        }
        return res;
    }
};



int main() {

    return 1;
}