#include "common.h"

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }
        for(auto n: nums){
            if(n >= s)
                return 1;
        }
        vector<int> partsum;
        partial_sum(nums.begin(), nums.end(), back_inserter(partsum));
        partsum.insert(partsum.begin(), 0);
        ++size;

        int len = 2;
        for(; len < size; ++len){
            for (int base = 0; base < size-len; ++base) {
                if (partsum[base + len] - partsum[base] >= s) {
                    return len;
                }
            }
        }
        return 0;
    }
};

int main() {
    //vector<int> data = {2,3,1,2,4,3};
    vector<int> data = {2,3,1,1,1,1,1};
    cout << Solution().minSubArrayLen(5, data);
    return 1;
}