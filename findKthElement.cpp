#include "common.h"
class Solution {
public:
    int partition(vector<int>& nums, int b, int e)
    {
        int p = nums[b];
        int ind = b+1;
        for(int i = b + 1; i < e; ++i)
        {
            if(nums[i] >= p)
                swap(nums[ind++], nums[i]);
        }
        swap(nums[b], nums[--ind]);
        return ind + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int t = 0;
        int b = 0, e = nums.size() ;
        while(t != k) {
            if(t < k)
                b = t;
            else //t > k
                e = t -1;
            t = partition(nums, b, e);
        }
        return nums[t-1];
    }
};


int main() {

    return 1;
}