#include "common.h"
//not checked yet

class NumArray {
private:
    map<pair<int, int>, int> m;
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            m[make_pair(0, i)] = sum;
        }
    }

    int sumRange(int i, int j) {
       int left = 0;
        if(i > 0)
            left = m[make_pair(0, i-1)];
        return m[make_pair(0, j)] - left;
    }
};



int main() {
    vector<int> data  {1, 4, -6};
    NumArray s{data};
    cout << s.sumRange(0, 2) << endl;
    cout << s.sumRange(1, 2) << endl;
    cout << s.sumRange(0, 1) << endl;

    return 1;
}