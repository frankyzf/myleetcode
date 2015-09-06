#include "common.h"
class Solution {
public:
    int trap(vector<int>& height) {
        const int size = height.size();
        if (size == 0) {
            return 0;
        }
        vector<int> left(size , 0);
        vector<int> right(size, 0);
        for (int i = 1; i < size; ++i) {
            left[i] = max(height[i-1], left[i-1]);
        }
        for (int i = size-2; i > 0; --i) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            int n = min(left[i], right[i]) - height[i];
            if(n > 0) {
                sum += n;
            }
        }
        return sum;
    }
};


int main() {

    return 1;
}