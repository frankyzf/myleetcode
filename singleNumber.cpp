#include "common.h"
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const size_t size = nums.size();
        vector<int> res(2,0);
        if(size <= 2){
            res.assign(nums.begin(), nums.end());
            return res;
        }
        int sxor = 0;
        for_each(nums.begin(), nums.end(), [&sxor](const int x){sxor ^= x;});
        int i  = 0x00000001;
        while((sxor & i) == 0)  {
            i = (i << 1);
        }
        for_each(nums.begin(), nums.end(),
                 [&res, i](const int x){
                     if(x&i)
                         res[0] ^= x;
                     else
                         res[1] ^= x; }
        );
        return res;
    }
};


int main() {
    vector<int> data {1, 2, 1, 3, 2, 5};
    auto r = Solution().singleNumber(data);
    for(auto i: r)
        cout << i << "," ;
    cout <<endl;
    return 1;
}