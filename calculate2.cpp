//
// Created by feng on 8/18/15.
//

#include "common.h"

class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> data;
        map<char, int> precedence{ {'+', 1}, {'-', 1}, {'*', 3}, {'/', 3}};

        auto opf = [&op, &data, &precedence](char ch){
            while(!op.empty() && precedence[ch] <= precedence[op.top()]){
                int b = data.top(); data.pop();
                int a = data.top(); data.pop();
                switch(op.top()){
                    case '+':
                        a += b;
                        break;
                    case '-':
                        a -= b;
                        break;
                    case '*':
                        a *= b;
                        break;
                    case '/':
                        a /= b;
                        break;
                }
                op.pop();
                data.push(a);
            }
            op.push(ch);
        };

        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == ' ')
                ++i;
            if(i == s.length())
                break;
            if (isdigit(s[i]) ){
                string ds;
                while(i < s.length() && isdigit(s[i])){
                    ds.push_back(s[i++]);
                }
                data.push(atoi(ds.c_str()));
            }
            else if(s[i] == '+'|| s[i] == '-'|| s[i] == '*'|| s[i] == '/' ){
                opf(s[i]);
                ++i;
            }
        }
        while(!op.empty()) {
            int b = data.top(); data.pop();
            int a = data.top(); data.pop();
            switch(op.top()){
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
            }
            op.pop();
            data.push(a);
        }
        return data.top();
    }
};


int main() {
    cout << Solution().calculate(" 3+5 / 2 ");
    return 1;
}