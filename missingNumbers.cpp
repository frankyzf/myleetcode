#include "common.h"

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        const size_t size = nums.size();
        if(size == 0)
            return 0;
        vector<bool> bs(size, false);
        for(auto i: nums){
            bs[i] = true;
        }
        for(int i = 0; i < size; ++i){
            if(!bs[i]){
                return i;
            }
        }
        return size;
    }
};


int main() {
    vector<int> num{0,1,3};
    cout << Solution().missingNumber(num) << endl;
    return 1;
}