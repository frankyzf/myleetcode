//
// Created by feng on 8/8/15.
//
#include "common.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            nums1.resize(n+m);
            return;
        }
        if(m == 0){
            auto end = nums2.begin();
            advance(end, n);
            copy(nums2.begin(), end, nums1.begin());
            nums1.resize(n+m);
            return;
        }



        int i1 = 0;
        int i2 = 0;
        vector<int> before(m, 0);
        while(i1 < m && i2 < n){
            int cnt = 0;
            if(i1 > 0);
                cnt = before[i1-1];
            while(i2 < n && nums2[i2] < nums1[i1]){
                ++i2;
                ++cnt;
            }
            before[i1++] = cnt;
        }

        if(i1<m){
            for(; i1< m; ++i1){
                before[i1] = before[i1-1];
            }
        }

        i1 = m-1; i2 = n-1;
        int j = n+m -1;
        while(j >= 0 ){
            while(j > before[i1] + i1){
                nums1[j--] = nums2[i2--];
            }
            nums1[j--] = nums1[i1--];
        }
    }
};


int main() {
    vector<int> m1{0,0,3,0,0,0,0,0,0};
    vector<int> m2{-1,1,1,1,2,3};
    Solution().merge(m1, 3, m2, 6);
    for(auto d: m1)
        cout << d << ",";
    cout << endl;
    return 1;
}