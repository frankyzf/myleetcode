#include "common.h"
/*
 * Given an array of integers, find out whether there are two distinct indices i and j in the array
 * such that the difference
 * between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int size = nums.size();
        if(size <= 1)
            return false;
        multiset<int> ms;
        for (int i = 0; i < size; ++i) {
            if(ms.size() >= k+1){
                ms.erase(ms.find(nums[i-k-1]));
            }
            auto it = ms.lower_bound(nums[i]-t);
            if (it != ms.end() && *it - nums[i] <= t) {
                return true;
            }
            ms.insert(nums[i]);
        }
        return false;
    }
};
int main() {
    vector<int> data = {1,2};
    cout <<boolalpha<< Solution().containsNearbyAlmostDuplicate(data, 0, 1);
    return 1;
}