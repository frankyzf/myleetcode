#include "common.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        map<string, int> pre{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};
        stack<int> data;
        for(int i = 0; i < tokens.size(); ++i){
            if(isdigit(tokens[i][0]) || tokens[i].length() > 1){
                data.push(atoi(tokens[i].c_str()));
            }
            else{
                int b = data.top();
                data.pop();
                int a = data.top();
                data.pop();
                if(tokens[i] == "+"){
                    data.push(a+b);
                }
                else if (tokens[i] == "-"){
                    data.push(a-b);
                }
                else if (tokens[i] == "*"){
                    data.push(a*b);
                }
                else if(tokens[i] == "/"){
                    data.push(a/b);
                }
            }
        }
        return data.top();

    }
};


int main() {

    return 1;
}