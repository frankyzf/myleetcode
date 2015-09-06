#include "common.h"

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string res;
        vector<pair<int, string> > describe{ {1000000000, " Billion ", }, {1000000, " Million "}, {1000, " Thousand "}, {1,""}};
        vector<string> digit {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> twenty {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> ten {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        for(auto& v: describe){
            int p = num/v.first;
            if(p > 0){
                bool bstart = false;
                if(p/100){
                    res += digit[p/100-1] + " Hundred";
                    p %=100;

                    bstart = true;
                }
                if(p/10 ){
                    if(bstart){
                        res += " ";
                        bstart = false;
                    }
                    if(p/10 == 1){
                        res += ten[p%10];
                        p = 0;
                    }
                    else{
                        res += twenty[p/10-2];
                        p %=10;
                        bstart = true;
                    }

                }
                if (p>0){
                    if(bstart){
                        res += " ";
                    }
                    res += digit[p-1];
                }
                res += v.second;
                num %= v.first;
            }
        }
        if(*res.rbegin() == ' '){
            res.pop_back();
        }
        return res;
    }
};


int main() {
    //cout << Solution().numberToWords(123) << endl;
    //cout << Solution().numberToWords(12345)<< endl;
    cout << Solution().numberToWords(1000)<< endl;
    return 1;
}