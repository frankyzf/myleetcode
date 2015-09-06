#include "common.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        const int size = nums.size();
        int range = nums[0];
        int base = 0;

        while(range > 0){
            int end = base + range;
            int maxindex = base;
            for(int i = base+1; i <= end; ++i){
                if(i+nums[i]> maxindex)
                    maxindex = i + nums[i];
                if(maxindex >= size-1)
                    return true;
            }
            base = end;
            range = maxindex - end;
        }
        return false;
    }
};


int main() {

    return 1;
}