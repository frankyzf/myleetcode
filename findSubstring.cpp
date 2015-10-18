#include "common.h"
//not checked yet

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size() ==0 || s.length() == 0)
            return res;
        const int len = words[0].length();
        const int totallen = len * words.size();
        int pos = 0;
        unordered_multiset<string> dict(words.begin(), words.end());

        for (int startpos = 0; startpos <= (int)s.length() - totallen; ++startpos) {
            auto pos = startpos;
            unordered_multimap<string, int> mm;
            while (pos < s.length()&& mm.size() < dict.size() ) {
                auto str = s.substr(pos, len);
                if (dict.count(str)) {
                    if(mm.count(str) < dict.count(str)){
                        mm.insert(make_pair(str, pos));
                    }
                    else {
                        auto cnt = mm.count(str);
                        auto range = mm.equal_range(str);
                        deque<int> rp;
                        for (auto r = range.first; r != range.second ; ++r) {
                            rp.push_back(r->second);
                        }
                        sort(rp.begin(), rp.end());
                        for (; cnt >= dict.count(str) ; --cnt) {
                            auto mit = mm.begin();
                            while (mit != mm.end()) {
                                if (mit->second <= rp[0]) {
                                    mit = mm.erase(mit);
                                }
                                else
                                    ++mit;
                            }
                            rp.pop_front();
                        }
                        if(pos > s.length()  - (totallen - len * mm.size()))
                            break;
                    }
                }
                else {
                    break;
                }
                pos+= len;
            }
            if(mm.size() == dict.size()){
                res.push_back( min_element(mm.begin(), mm.end(),
                [](const pair<const string, int>& left, const pair<const string, int>& right){
                    return left.second < right.second;
                })->second );
            }
        }
        return res;
    }
};



int main() {
    string s = "a";
    vector<string> dict {"a","a"};
    auto res = Solution().findSubstring(s, dict);
    for(auto v: res){
        cout << v << ",";
    }
    return 1;
}