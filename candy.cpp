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
//        for(auto c: candies)
//            cout << c << ";";
//        cout << endl;
        int right = candies[size-1];
        for (int j = size -2; j >= 0; --j) {
            if(ratings[j] > ratings[j+1]){
                candies[j] = max(candies[j], ++right);
            }
            else{
                right = ratings[j];
            }
        }
 //       for(auto c: candies)
 //           cout << c << ";";
 //       cout << endl;

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    vector<int> data{2,1};
    cout << Solution().candy(data);
    return 1;
}