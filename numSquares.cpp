#include "common.h"
//not checked yet
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;
        dp.push_back(0); // 1 --> 1 square;
        dp.push_back(1);
        for(int i = 2; i <=n ; ++i){
            int num = numeric_limits<int>::max();
            for(int j = 1; j*j <= i; ++j){
                int df = i - j*j;
                num = min(num, dp[df] + 1);
            }

            dp.push_back(num);
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numSquares(13);

    return 1;
}