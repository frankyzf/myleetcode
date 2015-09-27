#include "common.h"
//not checked yet

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {


        vector<vector<int>> res;
        function<bool(int, int, const vector<vector<int>>&)> ff =[&res, &candidates, &ff](int t, int start, const vector<vector<int>>& vec){
            if(t <0)
                return false;
            else if(t == 0){
                copy(vec.begin(), vec.end(), back_inserter(res));
                return true;
            }
            else if (start >= candidates.size())
                return false;
            else if (candidates[start] > t)
                return false;

            bool bret = false;

            for(int i = start; i < candidates.size() && candidates[i] <= t; ++i){
                if(i > start && candidates[i] == candidates[i-1])
                    continue;
                if(candidates[i] <= t){
                    vector<vector<int>> mvec(vec.begin(), vec.end());
                    for_each(mvec.begin(), mvec.end(), [i, &candidates](vector<int>& item){item.push_back(candidates[i]);});

                    if(ff(t-candidates[i], i+1, mvec)) {
                        bret = true;
                    }

                }
            }
            return bret;

        };
        vector<vector<int>> vv{vector<int>{}};
        sort(candidates.begin(), candidates.end());
        if(ff(target, 0, vv)){
            return res;
        }
        else{
            return vector<vector<int>>{};
        }

    }
};



int main() {
    vector<int> data {2,3,6,7};
    auto res = Solution().combinationSum(data, 7);
    for(auto v: res){
        for(auto n: v)
            cout << n < ",";
        cout << endl;
    }
    return 1;
}