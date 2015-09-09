#include "common.h"

//not checked yet

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        if(num.size()<4){
            return res;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size()-3; ++i) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            for (int j = i + 1; j < num.size() - 2; ++j){
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                for(int m = j+1; m < num.size() -1; ++m ) {
                    if (m > j + 1 && num[m] == num[m - 1]) {
                        continue;
                    }
                    int ps = num[i] + num[j] + num[m];
                    bool it;
                    it = binary_search(num.begin() + m + 1, num.end(), target - ps);
                    if(it ){
                        auto itt = lower_bound(num.begin()+m+1, num.end(), target-ps);
                        res.push_back(vector<int>{num[i], num[j], num[m], *itt});
                    }
                }
            }
        }
        return res;
    }


};


int main() {
    vector<int> data {1,0,-1,0,-2,2};

    auto res = Solution().fourSum(data, 0);
    for (auto &v: res) {
        for (auto n: v) {
            cout << n << ",";
        }
        cout << endl;
    }
    return 1;
}
