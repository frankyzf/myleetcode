#include "common.h"
//not checked yet

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size() == 0 || s.length() < words[0].length() * words.size())
            return res;

        unordered_map<string, int> umm;
        for(auto w:words){
            umm[w]++;
        }
        const int wlen = words[0].length();
        for (int i = 0; i < wlen; ++i) {
            unordered_map<string, int> tmpmm;
            int wcount = 0;
            for ( int j = i; j <= s.length() - wlen; j += wlen) {
                auto str = s.substr(j, wlen);
                if(umm.count(str) == 0){
                    wcount = 0;
                    tmpmm.clear();
                }
                else{
                    tmpmm[str]++;
                    wcount ++;
                    while(tmpmm[str] > umm[str]){
                        auto ts = s.substr(j-wcount*wlen + wlen, wlen);
                        tmpmm[ts] --;
                        wcount --;
                    }
                }

                if(wcount == words.size()){
                    res.push_back(j - words.size()*wlen + wlen);
                    auto headstr = s.substr(j - words.size()* wlen + wlen, wlen);
                    tmpmm[headstr]--;
                    wcount --;
                }
            }
        }
        return res;
    }

};



int main() {
    string s = "wordgoodgoodgoodbestword";
    vector<string> dict {"word","good","best","good"};
    auto res = Solution().findSubstring(s, dict);
    for(auto v: res){
        cout << v << ",";
    }
    cout << "end" << endl;
    return 1;
}