#include "common.h"
//not checked yet


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tstat;
        for(auto ch: t)
            tstat[ch] ++;
        deque<char> dq;
        unordered_map<char, int> stat;

        int res = numeric_limits<int>::max();
        int resstart = -1;

        int i = 0;
        for (; i < s.length() ; ++i) {
            if(tstat.count(s[i])){
                break;
            }
        }
        int start = i;

        for (; i < s.length(); ++i) {
            auto ch = s[i];
            dq.push_back(ch);
            if(tstat.count(ch) != 0){
                stat[ch]++;
                bool ball = true;
                for(auto& item: tstat){
                    if(stat[item.first] < item.second){
                        ball = false;
                        break;
                    }
                }
                if(ball){
                    while(tstat.count(dq.front())  == 0 || tstat[dq.front()] <= --stat[dq.front()] ){
                        start++;
                        dq.pop_front();
                    }
                    stat[dq.front()] ++;
                    while(tstat.count(dq.front()) == 0){
                        dq.pop_front();
                        start ++;
                    }

                    if(dq.size() < res){
                        resstart = start;
                        res = dq.size();
                    }
                }
            }
        }
        if(resstart >=0)
            return s.substr(resstart, res);
        return "";

    }
};




int main() {
    string s{"caae"};
    string t{"cae"};
    cout << Solution().minWindow(s, t);

    return 1;
}