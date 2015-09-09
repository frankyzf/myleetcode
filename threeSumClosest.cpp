#include "common.h"
//not checked yet
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest = numeric_limits<int>::max();
        sort(num.begin(), num.end());
        if(num.size() < 3)
            return closest;
        for(int i = 0; i < num.size(); ++i){
            if(i > 0 && num[i]  == num[i-1])
                continue;
            for(int j = i+1; j < num.size() -1; ++j){
                if(j > i+1 && num[j] == num[j-1]){
                    continue;
                }
                int ps = num[i]+num[j];
                auto it = lower_bound(num.begin()+j+1, num.end(), target-ps);
                if (it != num.begin() + j + 1 && abs(ps+*it-target)> abs(ps+*(it-1)-target)) {
                    -- it;
                }
                if(closest == numeric_limits<int>::max()
                   || abs(ps+*it - target) < abs(closest -target)){
                    closest = ps + *it;
                }
            }
        }
        return closest;
    }
};


int main() {
    vector<int> data{-1, 2, 1, -4};
    cout << Solution().threeSumClosest(data, 1);

    return 1;
}