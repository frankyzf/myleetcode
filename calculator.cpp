//
// Created by feng on 8/11/15.
//

#include "common.h"


class Solution {
public:
    int calculate(string s) {
        map<char, int> precedence{{'(', 0}, {'+', 1}, {'-', 1}, {')', 2 } };
        int val = 0;
        const int len = s.length();
        stack<char> st;
        stack<int> data;
        int i = 0;
        while(i < len){
            if(isdigit(s[i])){
                string d;
                do {
                    d.push_back(s[i++]);
                }while(isdigit(s[i]));
                data.push(stoi(d));
            }

            if(s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')' ){
                stack<char> ops;
                stack<int> ds;
                while(st.top()!= '('){
                    ds.push(data.top());
                    data.pop();
                    ops.push(st.top());
                    st.pop();
                };
                st.pop();
                if(!data.empty()){
                    ds.push(data.top());
                    data.pop();
                }

                while(!ops.empty()){
                    char op = ops.top(); ops.pop();
                    int a = ds.top(); ds.pop();
                    int b = ds.top(); ds.pop();
                    if(op == '+')
                        ds.push(a+b);
                    else // op == '-'
                        ds.push(a-b);
                }
                if(!ds.empty())
                    data.push(ds.top());
            }
            else if (s[i] == '+' || s[i] == '-'){
                st.push(s[i]);
            }
            ++i;
        }
        stack<char> ops;
        stack<int> ds;
        while(!st.empty()){
            ds.push(data.top());
            data.pop();
            ops.push(st.top());
            st.pop();
        };
        if(!data.empty()) {
            ds.push(data.top());
            data.pop();
        }
        while(!ops.empty()){
            char op = ops.top(); ops.pop();
            int a = ds.top(); ds.pop();
            int b = ds.top(); ds.pop();
            if(op == '+')
                ds.push(a+b);
            else // op == '-'
                ds.push(a-b);
        }

        return ds.top();
    }
};



int main(){
    cout << Solution().calculate("(4+9)");
    return 1;
}