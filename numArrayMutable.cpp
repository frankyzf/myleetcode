#include "common.h"
//not checked yet

class NumArray {
private:
    vector<int> num;
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size()+1);
        fill_n(num.begin(), nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            updatediff(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int prev = 0;
        if(i >= 1)
            prev = getSum(i-1);
        auto v = getSum(i);
        v -= prev;
        updatediff(i, val - v);
    }



    int sumRange(int i, int j) {
        int prev = 0;
        if(i > 0)
            prev = getSum(i-1);
        return getSum(j) - prev;
     }

    void updatediff(int i, int diff ){
        ++i;
        while(i < num.size()){
            num[i] += diff;
            i += i & (-i);
        }
    }
    int getSum(int i){
        ++i;
        int sum = 0;
        while(i > 0){
            sum += num[i];
            i -= i & (-i);
        }
        return sum;
    }
};

int main() {
    vector<int> data {5,18,13};
    NumArray na(data);
    cout << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0, 2);
    return 1;
}