#include "common.h"

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        unordered_map<char,vector<string> > capnum;
        for_each(dict.begin(), dict.end(), [&](const string& str){capnum[str[0]].push_back(str);});
        function<void(string, unordered_set<string>&, vector<string>& )> f
                = [&](string str, unordered_set<string>& flag, vector<string>& vv){
            if(str == ""){
                string rs = vv[0];
                for (int i = 1; i < vv.size(); ++i) {
                    rs += " " + vv[i];
                }
                res.push_back(move(rs));
            }
            if(flag.size() == dict.size())
                return ;
            if(capnum.count(str[0]) == 0)
                return;
            const auto& canv = capnum[str[0]];
            for (auto ss:canv) {
                if(flag.count(ss) == 0 && dict.count(ss)){
                    flag.insert(ss);
                    vv.push_back(ss);
                    f(str.substr(ss.length()), flag, vv);
                    flag.erase(ss);
                    vv.pop_back();
                }
            }
        };
        unordered_set<string> flag;
        vector<string> vv;
        f(s,flag, vv);
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