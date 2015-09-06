#include "common.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end =  nums.size()-1;
        while (begin < end )
        {
            const int mid = begin +  (end - begin)/2;
            if(nums[mid] < nums[end])
                end = mid;
            else if(nums[mid] > nums[end])
                begin = mid +1 ;
            else if(nums[begin] > nums[end])
                begin ++;
            else
                end --;
        }

        return nums[begin];
    }
};


int main() {

    return 1;
}