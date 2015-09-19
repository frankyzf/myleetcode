#include "common.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        if(size == 0)
            return 0;
        vector<int> candies(size, 1);
        int left = 1;
        for (int i = 1; i < size; ++i) {
            if(ratings[i] > ratings[i-1]){
                candies[i] = ++left;
            }
            else{
                left = 1;
            }
        }
#ifdef DEBUG
        for(auto c: candies)
            cout << c << ";";
        cout << endl;
#endif
        int right = candies[size-1];
        for (int j = size -2; j >= 0; --j) {
            if(ratings[j] > ratings[j+1]){
                ++right;
                candies[j] = max(candies[j], right);
            }
            else{
                right = candies[j];
            }
        }
#ifdef DEBUG
        for(auto c: candies)
            cout << c << ";";
        cout << endl;
#endif
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    vector<int> data{1,0,2};
    cout << Solution().candy(data);
    return 1;
}