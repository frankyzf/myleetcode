#include "common.h"

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;

        unordered_map<char,vector<string> > capnum;
        for_each(dict.begin(), dict.end(), [&](const string& str){capnum[str[0]].push_back(str);});
        vector<bool> possible(s.length()+1,true);

        auto startwith =[](const string& str, int pos, const string& head){
            for (int i = 0; i < head.length(); ++i) {
                if(pos+i >= str.length() || str[pos+i] != head[i] )
                    return false;
            }
            return true;
        };

        function<bool(int, vector<string>& )> f
                = [&](int pos, vector<string>& vv){
            if(pos >= s.length()){
                string rs = vv[0];
                for (int i = 1; i < vv.size(); ++i) {
                    rs += " " + vv[i];
                }
                res.push_back(move(rs));
                return true;
            }
            if(capnum.count(s[pos]) == 0)
                return false;
            const auto& canv = capnum[s[pos]];
            bool br = false;
            for (auto ss:canv) {
                int len = ss.length();
                if(pos+len <=s.length() && possible[pos+len] && dict.count(ss) && startwith(s, pos, ss)){
                    vv.push_back(ss);
                    bool b = f(pos+len,vv);
                    possible[pos+len] = b;
                    br |= b;
                    vv.pop_back();
                }
            }
            return br;
        };

        vector<string> vv;
        f(0, vv);
        return res;

    }
};


int main() {
    unordered_set<string>  dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    auto res = Solution().wordBreak(str, dict);
    for(auto item: res){
        cout << item << endl;
    }
    return 1;
}