#include "common.h"
//not checked yet
/*
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

 */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        function<void(int, int, int, vector<int>)> f = [&res, k, &f](int start, int kk, int target, vector<int> v){
           if(start > 9 || kk > k || target <= 0){
               return;
           }
            if(kk == k && start <= target && target <= 9){
                v.push_back(target);
                res.push_back(std::move(v));
                return ;
            }

            for(; start<=9 && start<target; ++start){
                vector<int> v1(v);
                v1.push_back(start);
                f(start+1, kk+1, target-start, std::move(v1));

            }
            return;

        };
        f(1, 1, n, vector<int>{});
        return res;
    }
};

int main() {
    auto vv = Solution().combinationSum3(3, 9);
    for(auto& v: vv) {
        for(auto i: v)
            cout << i << ";";
        cout << endl;
    }
    return 1;
}