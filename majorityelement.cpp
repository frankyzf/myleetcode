#include "common.h"
//not checked yet
/*
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * The algorithm should run in linear time and in O(1) space.
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int size = nums.size();
        if(size < 3)
            return nums;
        vector<int> res;
        vector<int> cnt;
        for(int i = 0; i < size; ++i){
            if(res.size()  == 0){
                res.push_back(nums[i]);
                cnt.push_back(1);
            }
            else if(res.size() ==1){
                if(nums[i] == res[0]){
                    cnt[0]++;
                }
                else {
                    res.push_back(nums[i]);
                    cnt.push_back(1);
                }
            }
            else if(nums[i] == res[0]){
                cnt[0]++;
            }
            else if (nums[i] == res[1]){
                cnt[1]++;
            }
            else{
                for_each(cnt.begin(), cnt.end(), [&](int& n){--n;});
                if(cnt[0] == 0){
                    if(cnt[1] == 0){
                        res.clear();
                        cnt.clear();
                    }
                    else{
                        res[0] = res[1]; res.pop_back();
                        cnt[0] = cnt[1]; cnt.pop_back();
                    }
                }
                else if (cnt[1] == 0){
                    res.pop_back();
                    cnt.pop_back();
                }
            }
        }
        vector<int> res1;
        for(auto i: res){
            int n = 0;
            for_each(nums.begin(), nums.end(), [&n, i](const int& nm){if(nm == i) ++n;});
            if(n > size/3)
                res1.push_back(i);
        }
        return res1;

    }
};
int main() {
    vector<int> data{1,1, 2,3, 3};
    auto r = Solution().majorityElement(data);
    for(auto n: r)
        cout << n << ",";
    cout << "h" << endl;
    return 1;
}