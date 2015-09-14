#include "common.h"
class Solution{
public:
    int maxProfit(int k, vector<int> prices){
        const int size = prices.size();
        int res = 0;
        if(size <=1 || k<=0){
            return 0;
        }
        else if (size <= k){
            for(int i = 1; i < size; ++i){
                if(prices[i] - prices[i-1] > 0){
                    res += (prices[i] - prices[i-1]);
                }
            }
            return res;
        }

        vector<int> local(k, 0);
        vector<int> global(k, 0);
        for(int i = 1; i < size; ++i){
            int diff =prices[i] - prices[i-1];
            for(int j = k-1; j >= 0; --j){
                local[j] = max(local[j] + diff, global[j-1] + max(diff, 0));
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k-1];
    }
};


int main() {
    vector<int> prices{1,2,4};
    cout << Solution().maxProfit(2, prices);
    return 1;
}