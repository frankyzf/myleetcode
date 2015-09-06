#include "common.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, k = 0, j = nums.size()-1;
        for(; k <= j; ++k )
        {
            if(nums[k] == 0)
                swap(nums[i++], nums[k]);
            else if (nums[k] == 2)
                swap(nums[j--], nums[k--]);

        }
    }
};


int main() {

    return 1;
}