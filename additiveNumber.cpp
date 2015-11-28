#include "common.h"
//not checked yet

class Solution {
public:
    bool isAdditiveNumber(string num) {
        function<bool(long long, long long, int)> f = [&num, &f](long long a, long long b, int pos ){
            if(pos >= num.length())
                return true;
            long long c = 0;
            for (int i = pos; i < num.length() ; ++i) {
                if(num[pos] == '0' && i > pos)
                    return false;

                c = c*10 + num[i] - '0';
                if(c == a+b  && f(b, c, i+1))
                    return true;
                else if (c > a+b)
                    return false;
            }
            return false;
        };
        if(num.length() < 3)
            return false;
        long long a = 0;
        for (int i = 0; i < num.length() - 2; ++i) {
            if(num[0] == '0' && i > 0)
                break;
            a = a*10 + num[i] - '0';
            long long b = 0;
            for (int j = i+1; j < num.length() - 1; ++j) {
                if(num[i+1] == '0' && j > i+1)
                    break;
                b = b*10 + num[j] - '0';
                long long c = 0;
                for (int k = j+1; k < num.length(); ++k) {
                    if(num[j+1] == '0' && k > j+1)
                        break;
                    c = c*10 + num[k] - '0';
                    if(c > a+b)
                        break;
                    else if (c == a+b) {
                        if(f(b, c, k+1))
                            return true;
                        else
                            break;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    cout << Solution().isAdditiveNumber("023");
    return 1;
}