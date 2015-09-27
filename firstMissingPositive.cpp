#include "common.h"
//not checked yet
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> ss;
        for(auto n: nums)
            ss.insert(n);
        int missing = 1;
        while(ss.find(missing) != ss.end()){
            ++missing;
        }
        return missing;

    }
};
int main() {

    return 1;
}