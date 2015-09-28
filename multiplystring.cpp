#include "common.h"
//not checked yet
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) {
            return "";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        for (int i = 0; i < num1.size(); ++i) {
            int m1 = num1[i] - '0';
            int carry = 0;
            int r;
            for (int j = 0; j < num2.size(); ++j) {
                int m2 = num2[j] - '0';
                if(res.length()<=(i+j)){
                    r = (m1*m2 + carry);
                    carry = r/10;
                    r = r%10;
                    res.push_back((char)(r+'0'));
                }
                else{
                    r = (m1*m2 + carry + res[i+j] - '0');
                    carry = r/10;
                    r = r%10;
                    res[i+j]= (char)(r+'0');
                }
            }
            if(carry){
                if(res.length()<=(i+num2.length())){
                    r = carry;
                    carry = r/10;
                    r = r%10;
                    res.push_back((char)(r+'0'));
                }
                else{
                    r = ( carry + res[i+num2.length()] - '0');
                    carry = r/10;
                    r = r%10;
                    res[i+num2.length()]= (char)(r+'0');
                }
            }

        }
        reverse(res.begin(), res.end());
        int i = 0;
        for(; i < res.length()-1; ++i){
            if(res[i] != '0')
                break;
        }
        res = res.substr(i);
        return res;
    }
};



int main() {
    cout << Solution().multiply("9", "9");
    return 1;
}