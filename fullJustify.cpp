#include "common.h"
//not checked yet
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        int n = 0;
        while(n < words.size()) {
            int gn = n;
            int len = 0;
            while (gn < words.size() && len + words[gn].length() <= maxWidth) {
                len += words[gn].length() + 1;
                ++gn;
            }

            int cnt = gn - n;
            len -= cnt;
            vector<char> str(maxWidth, ' ');
            int totalgap = maxWidth - len;
            vector<int> gaps;

            if(gn == words.size()){
                for(int m = n ; m < gn; ++m)
                    gaps.push_back(1);
            }
            else {
                if (cnt == 1)
                    gaps.push_back(totalgap);
                else {
                    int ccn = cnt - 1;
                    while (ccn > 0) {
                        int avggap = totalgap / ccn;
                        gaps.insert(gaps.begin(), avggap);
                        totalgap -= avggap;
                        --ccn;
                    }
                }
            }
            int i = 0;
            strncpy(&str[i], words[n].c_str(), words[n].length());
            i += words[n].length();
            i += gaps[0];
            ++n;
            int c = 1;
            while(n < gn){
                strncpy(&str[i], words[n].c_str(), words[n].length());
                i  += words[n].length();
                if(n < gn-1)
                    i += gaps[c];
                ++n;
                ++c;
            }
            res.push_back(string(str.begin(), str.end()));
        }
        return res;
    }
};


int main() {
    vector<string> words{"what", "must","be","shall","be"};
    auto r = Solution().fullJustify(words, 12);
    for(auto s: r){
        cout << s << endl;
    }
    return 1;
}