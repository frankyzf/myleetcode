#include "common.h"
//not checked yet

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
            return 0;
        stack<int> st;
        vector<int> mark(s.length(), 0);

        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else {
                if(st.empty()){ //error happened
                    mark[i] = -1;
                }
                else{
                    mark[i] = 1;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            mark[st.top()] = -1;
            st.pop();
        }
        int target = 0;

        int i = 0;
        while(i < s.length()){
            int num = 0;
            while(i<s.length() && mark[i] != -1){
                num += mark[i];
                ++i;
            }
            target = max(num*2, target);
            ++i;
        }
        return target;
    }
};

int main() {
    cout << Solution().longestValidParentheses("())");
    return 1;
}