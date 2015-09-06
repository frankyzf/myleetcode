#include "common.h"
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<vector<int>> {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.emplace_back(vector<int>(nums.begin(), nums.end()));
        while(next_permutation(nums.begin(), nums.end())){
            res.emplace_back(vector<int>(nums.begin(), nums.end()));
        }
        return res;
    }
};


int main() {

    return 1;
}