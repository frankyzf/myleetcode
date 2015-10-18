#include "common.h"
//not checked yet

class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {
        stringstream ss;
        long long numerator = abs((long long)numerator1);
        long long denominator = abs((long long) denominator1);
        long long aa = numerator/denominator;
        if(numerator1 < 0 && denominator1 >0 || numerator1 > 0 && denominator1 < 0)
            ss << "-";
        numerator = numerator - aa * denominator;
        ss << aa;
        if(numerator == 0)
            return ss.str();


        unordered_map<int, int> mpos;

        ss << '.';
        int pos = ss.str().length();
        mpos[numerator] = pos;
        numerator *=10;
        while(numerator < denominator){
            ss << "0";
            pos = ss.str().length();
            mpos[numerator] = pos;
            numerator *=10;
        }


        while(true){
            int divider = numerator/denominator;
            numerator %= denominator;
            ss << divider;
            if(numerator ==0)
                break;
            else {
                auto it = mpos.find(numerator);
                if ( it != mpos.end()){
                    auto ppos = it->second;
                    string str = ss.str();
                    str.insert(ppos, "(");
                    str.append(")");
                    return str;
                }
                else{
                    pos = ss.str().length();
                    mpos[numerator] = pos;
                    numerator *=10;
                    while(numerator < denominator){
                        ss << "0";
                        mpos[numerator] = ss.str().length();
                        numerator *=10;
                    }
                }
            }
        }
        return ss.str();

    }
};

int main() {
    cout << Solution().fractionToDecimal(1, 90);
    return 1;
}