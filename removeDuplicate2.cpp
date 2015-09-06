#include "common.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int m = nums.size();
        if(m == 0)
            return 0;
        int j = 1;
        bool flag = false;
        for(int i = 1; i <m; ++i)
        {
            if(nums[i] != nums[i-1])
            {
                flag = false;
                nums[j++]  = nums[i];
            }
            else if( flag == false)
            {
                flag = true;
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};


int main() {

    return 1;
}