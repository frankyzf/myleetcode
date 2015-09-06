#include "common.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        vector<int> nums(n.begin(), n.end());
        sort(nums.begin(), nums.end());
        auto left = nums.begin();
        auto right = nums.end() -1;
        while(left < right)
        {
            int s = *left + *right;
            if(s == target)
                break;
            else if(s < target)
                left ++;
            else
                right --;
        }
        int index1 = distance( n.begin() , find(n.begin(), n.end(), *left)) + 1;
        int index2 = distance(n.begin(), find(n.rbegin(), n.rend(), *right).base() -1 ) + 1;
        if(index1 > index2)
            swap(index1, index2);
        return vector<int>{index1, index2};

    }
};


int main() {

    return 1;
}