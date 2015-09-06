#include "common.h"
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto f = [](int n){
            int base = 10;
            while(n/base){
                base *= 10;
            }
            return base/10;
        };
        const int size = nums.size();
        string res;
        if(size == 0)
            return res;
        else if (size == 1){
            ostringstream sstr;
            sstr << nums[0];
            return sstr.str();
        }
        deque<string> ss;

        transform(nums.begin(), nums.end(), back_inserter(ss), [](int n){  ostringstream sstr; sstr << n; return sstr.str();});
        sort(ss.begin(), ss.end(), [](const string& l, const string& r) {return l+r > r+l;}  );
        for_each(ss.begin(), ss.end(), [&res](const string& item){res += item;});

        int i = 0;
        while(i <res.length() && res[i] =='0'){
            ++i;
        }
        if(i == res.length())
            --i;
        return res.substr(i, string::npos);
    }
};


int main() {

    return 1;
}