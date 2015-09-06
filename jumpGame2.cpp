#include "common.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        const int size = nums.size();
        if(size <= 1)
            return 0;
        int step = 0;
        int range = nums[0];
        int base = 0;
        bool valid = false;
        while(valid == false && range >0){
            ++ step;
            int end = base + range;
            if(end >= size-1)
            {
                valid = true;
                break;
            }
            int maxindex = end;
            for(int i = base +1; i <= end; ++i){
                if(i+nums[i]> maxindex)
                    maxindex = i+nums[i];
            }
            base = end;
            range = maxindex - end;
        }

        if(!valid )
            return -1;
        else
            return step;

    }
};


int main() {

    return 1;
}