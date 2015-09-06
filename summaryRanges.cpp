//
// Created by feng on 7/28/15.
//

#include "common.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start, end, last;
        vector<string> res;
        if(nums.empty())
            return res;

        const int size = nums.size();
        start = last = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] != last+1) {
                if (last == start)
                    res.push_back(to_string(last));
                else {
                    res.push_back(to_string(start) + "->" + to_string(last));
                }
                start = last = nums[i];
            }
            else
            {
                last = nums[i];
            }
        }

        if (last == start)
            res.push_back(to_string(last));
        else
            res.push_back(to_string(start) + "->" + to_string(last));
        return res;
    }
};


int main()
{
    vector<int> data = {0,1,2,4,5,7};
    auto r = Solution().summaryRanges(data);
    for (auto v: r)
        cout << v << ", ";
    cout << endl;

    return 1;
}
