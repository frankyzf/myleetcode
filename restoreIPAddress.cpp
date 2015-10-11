#include "common.h"
//not checked yet


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() == 0)
            return res;
        function<void(int, size_t, vector<int> )> f = [&s, &f, &res](int partnum, size_t pos, vector<int> parts){
            if(partnum == 3) {
                if (pos < s.length()) {
                    if(s[pos] != '0' || s[pos] == '0' && pos == s.length()-1 ) {
                        int num = atoi(s.substr(pos).c_str());
                        if (num >= 0 && num <= 255) {
                            parts.push_back(num);
                            stringstream ss;
                            for_each(parts.begin(), parts.end(), [&ss](int i) { ss << i << "."; });
                            res.push_back(ss.str().substr(0, ss.str().length() - 1));
                            parts.pop_back();
                            return;
                        }
                    }
                }
            }
            else{ // partnum < 3
                if(pos < s.length() && s[pos] == '0'){
                    parts.push_back(0);
                    f(partnum+1, pos+1, parts);
                    parts.pop_back();
                }
                else{
                    for(int i = 0; i < 3&&i+pos < s.length(); ++i){
                        int num = atoi(s.substr(pos, i+1).c_str());
                        if(num >=0 && num <= 255){
                            parts.push_back(num);
                            f(partnum+1, pos+i+1,parts);
                            parts.pop_back();
                        }
                    }
                }
            }
        };
        vector<int> parts;
        f(0, 0, parts);
        return res;
    }
};



int main() {
    auto res = Solution().restoreIpAddresses("010010");
    for (auto s: res){
        cout << s << endl;
    }
    return 1;
}