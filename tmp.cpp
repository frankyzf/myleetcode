#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(target == 0 || candidates.size() == 0)
            return res;

        int len = distance(candidates.begin(), lower_bound(candidates.begin(), candidates.end(), target));

    }
};
int main(){
    cout << Solution().simplifyPath("/..");
    return 1;
}