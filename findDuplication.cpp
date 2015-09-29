#include "common.h"
//not checked yet
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const size_t size = nums.size();
        if(size <= 1)
            throw invalid_argument("");
        vector<bool> flag(size+1, false);
        for(auto n: nums){
            if(flag[n] == true)
                return n;
            flag[n] = true;
        }
        return -1;

    }
};
int main() {

    return 1;
}