#include "common.h"
//not checked yet
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if(size < 2)
            return 0;
        int i = 0;
        int sum = 0;
        while(i < size){
            while(i<size-1 && prices[i] > prices[i+1]){
                ++i;
            }
            int  low = prices[i];
            ++i;
            while (i < size && prices[i] > prices[i - 1]) {
                ++i;
            }
            int high = prices[i-1];
            sum += (high - low);
        }
        return sum
    }

};



int main() {

    return 1;
}