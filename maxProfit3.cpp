#include "common.h"
//not checked yet
class Solution{
public:
    int maxProfit(vector<int>& prices){
        //O(n^2)
        auto f = [&prices](int i, int j){
            if(n >= j)
                return 0;
            vector<int> h;
            int r = numeric_limits<int>::min();
            for(int k = j-1; k >= i; --k){
                if(r < prices[k]){
                    r = prices[k];
                }
                h.push_back(r);
            }
            reverse(h.begin(), h.end());
            int res = 0;
            for (int k = i; k < j; ++k) {
                if(res < h[k-i] - prices[k]) {
                    res = h[k-i] - prices[k];
                }
            }
            return res;
        };
        auto r = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(r < (f(0, i) + f(i, prices.size()))){
                r = f(0, i) + f(i, prices.size());
            }
        }
        return r;
    }
};


int main() {

    return 1;
}