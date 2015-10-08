#include "common.h"
//not checked yet



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;

        if(nums.size() == 0)
            return vector<vector<int>>{};
        sort(nums.begin(), nums.end());

        function<void(int, vector<int>& )> f = [&f, &nums, &res](int start, vector<int>& v){
            if(start == nums.size()){
                res.insert(v);
            }
            else{
                v.push_back(nums[start]);
                f(start+1, v);
                v.pop_back();
                f(start+1, v);
            }
        };
        vector<int> v;
        f(0, v);
        return vector<vector<int>>(res.begin(), res.end());
    }
};



int main() {
    vector<int> data {1,2,2};
    auto res = Solution().subsetsWithDup(data);
    for (auto &v : res) {
        for (auto item : v) {
            cout << item << ",";
        }
        cout << endl;
    }
    return 1;
}