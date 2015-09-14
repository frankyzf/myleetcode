#include "common.h"
class Solution{
public:
    int maxProfit(vector<int>& prices){
        //O(n)
        const int size = prices.size();
        if(size <=1){
            return 0;
        }
        else if (size == 2){
            return prices[1]-prices[0] > 0? prices[1] - prices[0]:0;
        }
        //left scan to get maxprofit from (0,i);
        vector<int> leftprofit(1,0);
        int low = prices[0];
        int profit = 0;
        for (int i = 1; i < size; ++i) {
            if (low > prices[i-1]) {
                low = prices[i-1];
            }
            if(profit < prices[i] - low){
                profit = prices[i] - low;
            }
            leftprofit.push_back(profit);
        }

        //right scan
        deque<int> rightprofit(1,0);
        int high = prices[size-1];
        profit = 0;
        for(int i = size-2; i >=0; --i){
            if(high < prices[i+1]){
                high = prices[i+1];
            }
            if(profit < high - prices[i]){
                profit = high - prices[i];
            }
            rightprofit.push_front(profit);
        }

        profit = 0;
        for(int i =1; i <size-1; ++i){
            if(leftprofit[i] + rightprofit[i] > profit){
                profit = leftprofit[i] + rightprofit[i];
            }
        }
        return profit;
    }
};


int main() {
    vector<int> data = {1,2,4};
    cout << Solution().maxProfit(data);
    return 1;
}