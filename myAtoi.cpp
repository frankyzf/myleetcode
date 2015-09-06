//
// Created by feng on 8/10/15.
//

#include "common.h"

class Solution {
public:
    int myAtoi(string str) {
        bool positive = true;
        string body ;
        auto it = str.begin();
        while(it != str.end() && *it == ' ')
            ++it;
        if(it == str.end()|| ! (isdigit(*it)||*it == '-'||*it == '+') )
            return 0;

        if(*it == '-'){
            positive = false;
            ++ it;
        }
        else if (*it == '+'){
            positive = true;
            ++ it;
        }
        while( it != str.end() && isdigit(*it)){
            body.push_back(*it);
            ++it;
        }
        bool valid = true;
        if(body.length() == 0)
            return 0;
        if(body.length()>10 ){
            valid = false;
        }
        else if (body.length() == 10){
            if(positive){
                if(body > "2147483647")
                    valid = false;
            }
            else{
                if(body > "2147483648")
                    valid = false;
            }
        }

        if(valid == false){
            if(positive)
                return 2147483647;
            else
                return -2147483648;
        }
        else{
            int len = body.length();
            int sign = (positive? 1: -1);
            int val = (*body.begin()-'0') * sign * pow(10, len-1);
            for(int i = 1; i < len; ++i){
                val  +=  sign * (body[i] - '0') * pow(10, len -i -1);
            }
            return val;

        }
    }
};


int main(){
    cout << Solution().myAtoi("+-2");
    return 1;
}