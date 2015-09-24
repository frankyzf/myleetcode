#include "common.h"
//not checked yet

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        stack<int> st;
        int res = 0 ;
        int base;
        int len;

        for (int i = 0; i < height.size(); ++i) {
            if(st.empty() || height[st.top()] <= height[i]) {
                st.push(i);
            }
            else{
                while(!st.empty() && height[st.top()] > height[i]){
                    len = height[st.top()];
                    st.pop();
                    base = st.empty()?0:st.top()+1;
                    res = max<int>(res, len *(i - base) );
                }
                st.push(i);
            }
        }
        while (!st.empty() && height[st.top()] != 0) {
            len = height[st.top()];
            st.pop();
            base = st.empty()?0:st.top()+1;
            res = max<int>(res, len *(height.size() - base) );
        }
        return res;
    }
};

int main() {
    vector<int> data{4,2,0,3,2,5};
    cout << Solution().largestRectangleArea(data);

    return 1;
}