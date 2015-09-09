#include "common.h"
// not checked yet
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        if(num.size() < 3) {
            return res;
        }
        for (int i = 0; i < num.size(); ++i) {
            if(i > 0 && num[i] == num[i-1])
                continue;
            int j = i+1, k = num.size() -1;
            while (j < k) {
                if(j > i+1 && num[j] == num[j-1]){
                    ++j;
                    continue;
                }

                int ss = num[i]+num[j]+num[k];
                if(ss == 0) {
                    res.push_back(vector<int>{num[i], num[j], num[k]});
                    ++j; --k;
                }
                else if (ss > 0) {
                    --k;
                }
                else {
                    ++j;
                }
            }
        }
        return res;
    }
};



int main() {
    vector<int> data = {-1, 1, 1, 1, -1, -1, 0,0,0};    //int a[] = {-1, 0, 1, 2, -1, 1, -4};
    auto res = Solution().threeSum(data);
    for(auto& r: res) {
        for (auto n: r) {
            cout << n << ",";
        }
        cout << endl;
    }
    return 1;
}