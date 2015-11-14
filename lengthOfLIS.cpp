#include "common.h"
//not checked yet

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        multimap<int, int> mm;// len --> endint
        int  res = 0;
        for(auto n: nums){
            auto rit = mm.rbegin();
            for(; rit != mm.rend(); ++rit){
                if(rit->second < n)
                    break;
            }
            if(rit == mm.rend()) {
                mm.insert(make_pair(1, n));
                res = max(res, 1);
            }
            else{
                //cout << "n:" << n << " beforeint:" << rit->second << " length:" << rit->first +1 << endl;
                res  = max(res,  rit->first+1);
                mm.insert(make_pair(rit->first+1, n));
            }
        }

        return res;
    }
};

int main() {
    vector<int> data = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(data);
    return 1;
}