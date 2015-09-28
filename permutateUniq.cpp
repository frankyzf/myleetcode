#include "common.h"
//not checked yet
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(true){
            int i = nums.size()-2;
            for ( ;i >= 0; --i) {
                if (nums[i] < nums[i + 1]) {
                    break;
                }
            }
            if(i == -1)
                break;

            int j = i+1;
            for(; j < nums.size(); ++j){
                if(nums[j]< nums[i]){
                    break;
                }
            }
            --j;
            while(nums[j] == nums[i])
                --j;
            swap(nums[i], nums[j]);
            sort(nums.begin()+ i+1, nums.end());
            res.push_back(nums);
        }
        return res;
    }
};

int main() {
    vector<int> data{1,1,2};
    auto vs = Solution().permuteUnique(data);
    for(auto v: vs){
        for(auto n: v){
            cout << n << ",";
        }
        cout <<endl;
    }
    return 1;
}