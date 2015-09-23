#include "common.h"
//not checked yet

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const auto size = nums.size();
        if(size < 0)
            return;
        int i = 0;
        for(int j = 0; j < size; ){
            if(nums[j] == 0){
                ++j;
            }
            else{
                nums[i++] = nums[j++];
            }
        }
        fill(nums.begin()+i, nums.end(), 0);

    }
};



int main() {

    return 1;
}