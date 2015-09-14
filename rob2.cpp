#include "common.h"
class Solution {
public:
    int rob(vector<int> &nums) {
        const int size = nums.size();
        if(size  == 0) {
            return 0;
        }
        else if (size == 1)
            return nums[0];

        vector<int> data(size, 0);
        data[0]= nums[0];
        data[1]= nums[0];
        //rob the first house
        for(int i = 2; i < size-1; ++i){
            data[i] = max(data[i-2]+nums[i], data[i-1]);
        }
        auto it = max_element(data.begin(), data.end());
        int mm = *it;

        //do not rob the first house
        vector<int> mindata(size, 0);
        mindata[0] = 0;
        mindata[1] = nums[1];
        for(int i = 2; i < size; ++i){
            mindata[i] = max(mindata[i-2]+nums[i], mindata[i-1]);
        }
        it = max_element(mindata.begin(), mindata.end());
        if(mm < *it){
            mm = *it;
        }
        return mm;

    }
};


int main() {

    return 1;
}