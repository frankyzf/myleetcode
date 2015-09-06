#include "common.h"
class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t size = nums.size();
        vector<int> left(size+1);
        vector<int> result;
        left[0] = 1;
        for(int i = 0; i < size; ++i) {
            left[i+1] = left[i] * nums[i];
        }


        int p = 1;
        for(int i = size-1; i >= 0; --i) {
            result.push_back(p * left[i]);
            p *= nums[i];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {

    return 1;
}