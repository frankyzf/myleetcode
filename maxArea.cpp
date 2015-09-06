//
// Created by feng on 8/11/15.
//

#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        const int size = height.size();
        int left = 0, right = size  -1;
        while(left < right){
            int h = min(height[left], height[right]);
            int l = right - left;
            if(h*l > maxarea)
                maxarea = h*l;
            if(h == height[left])
                ++left;
            else
                --right;
        }
        return maxarea;
    }
};


int main(){
    return 1;
}