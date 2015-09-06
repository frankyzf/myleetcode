#include "common.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        const int size = nums.size();

        res.push_back(vector<int>{});
        if(!size)
            return res;
        for(int len = 1; len <= size; ++len){
            vector<int> m(size, 0);
            for(int j = size-1; j > size-1-len; --j){
                m[j] = 1;
            }

            do {
                vector<int> r;
                for(int k = 0; k <size; ++k){
                    if(m[k]){
                        r.push_back(nums[k]);
                    }
                }
                sort(r.begin(), r.end());
                res.push_back( move(r) );
            }while(next_permutation(m.begin(), m.end()));
        }
        return res;
    }
};



int main() {

    return 1;
}