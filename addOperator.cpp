#include "common.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        char* ptmp;
        function<void(long long, long long, long long, string)> f = [&f, &num, target, &res, &ptmp](long long pos, long long sum, long long lastnum, string str){
            if(pos == num.length()){
                if((sum + lastnum) == (long long)target)
                    res.push_back(str);
                return;
            }
            int end = num.length();
            if(num[pos] == '0')
                end = pos +1;
            for (int i = pos; i < end; ++i) {
                string dstr = num.substr(pos, i-pos+1);
                long long n = strtoll(dstr.c_str(), &ptmp,  10);
                f(i+1, sum,  lastnum * n, str +"*" + dstr);
                f(i+1, sum + lastnum, n, str + "+" + dstr);
                f(i+1, sum + lastnum, -n, str +"-" + dstr);
            }
        };

        int end = num.length();
        if(num[0] == '0')
            end = 1;
        for (int i = 0; i < end; ++i) {
            string dstr = num.substr(0, i+1);
            long long n = strtoll(dstr.c_str(), &ptmp,  10);;
            f(i+1, 0,  n, dstr);
        }
        return res;
    }
};

int main(){
    auto r = Solution().addOperators("2147483648", -2147483648);
    for(auto s: r)
        cout << s << endl;

    return 1;
}