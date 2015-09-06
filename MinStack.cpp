//
// Created by feng on 8/7/15.
//

#include "common.h"

class MinStack {
public:
    void push(int x) {
        if(data.size() == 0){
            min.push(x);
        }
        else if(min.top() >= x){
            min.push(x);
        }
        data.push(x);
    }

    void pop() {
        int d = data.top();
        if(d == min.top())
            min.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min;
};


int main()
{
    auto s = MinStack();
    s.push(2);s.push(0);s.push(3);s.push(0);
    for(int i = 0; i< 4; ++i)
    {
        cout << s.getMin() << endl;
        s.pop();
    }
}