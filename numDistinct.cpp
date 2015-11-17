#include "common.h"
//not checked yet


class Solution {
public:
    int numDistinct(string s, string t) {
        int si = 0, ti = 0;
        map<pair<int, int>, int> nums;
        function<int(int,int)> f = [&](int si, int ti)->int{
            if(si == s.length()){
                if(ti == t.length())
                    return 1;
                return 0;
            }
            if(ti == t.length())
                return 1;

            if(nums.count(make_pair(si, ti)))
                return nums[make_pair(si,ti)];
            int n = 0;
            for (int i = si; i < s.length(); ++i) {
                if(s[i] == t[ti])
                    n += f(i+1, ti+1);
            }
            nums[make_pair(si, ti)] = n;
        };
        return f(0,0);
    }
};

int main() {
    cout << Solution().numDistinct("rabbbit", "rabbit");
    return 1;
}