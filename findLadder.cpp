#include "common.h"
//not checked yet
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        if (wordList.size() == 0 || beginWord.length() == 0 || endWord.length() == 0) {
            return res;
        }
        if (beginWord == endWord) {
            res.push_back(vector<string>{beginWord});
            return res;
        }

        unordered_multimap<string, string> upstream;

        auto diff = [](const string &str1, const string &str2) {
            int len1 = str1.length();
            int len2 = str2.length();
            int len = min(len1, len2);
            int cnt = 0;
            for (int i = 0; i < len; ++i) {
                if (str1[i] != str2[i])
                    ++cnt;
                if (cnt >= 2)
                    return 2;
            }
            cnt += max(len1, len2) - len;
            return cnt;
        };

        queue<string> qt;
        qt.push(beginWord);
        int len = 0;
        bool bContinue = true;
        upstream.insert(make_pair(beginWord, ""));

        while (bContinue && !qt.empty()) {
            ++len;
            queue<string> tmpq;
            unordered_multimap<string, string> currentup;
            while (!qt.empty()) {
                auto str = qt.front();
                qt.pop();
                //cout << "L" << len << " " << str << endl;
                auto oldstr = str;
                for (int i = 0; i < str.length(); ++i) {
                    char och = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = (char) (j + 'a');
                        if ((wordList.count(str) || str == endWord)&& upstream.count(str) == 0) {
                            //cout << oldstr << "-->" << str <<endl;
                            tmpq.push(str);
                            currentup.insert(make_pair(str, oldstr));
                            if (str == endWord) {
                                bContinue = false;
                            }
                        }
                        str[i] = och;
                    }
                }
            }
            qt.swap(tmpq);
            for(auto it = currentup.begin(); it != currentup.end(); ++it){
                //cout << "upstream:" << it->first << " " << it->second << endl;
                upstream.insert(make_pair(it->first, it->second));
            }

        }

        if (!bContinue) {
            queue<string> qw;
            qw.push(endWord);
            res.push_back(vector<string>{endWord});
            while (!qw.empty()) {
                string word = qw.front();
                qw.pop();
                auto rit = upstream.equal_range(word);

                vector<vector<string>> tt;
                res.swap(tt);

                bool bFound = false;

                for (int i = 0; i < tt.size(); ++i) {
                    if (word == beginWord || tt[i].back() != word) {
                        res.push_back(move(tt[i]));
                    }
                    else {
                        auto b = rit.first;
                        for (auto b = rit.first; b != rit.second; b++) {
                            vector<string> tmppath(tt[i]);
                            tmppath.push_back(b->second);
                            res.push_back(move(tmppath));
                            bFound = true;
                        }
                    }
                }

                if(bFound){
                    for(auto b = rit.first; b != rit.second; b++){
                        qw.push(b->second);
                    }
                }
            }
        }
        for_each(res.begin(), res.end(), [](vector<string>& path){reverse(path.begin(), path.end());});
        return res;
    }
};

int main() {
    unordered_set<string> wordList {"hot","dot","dog","lot","log"};
    string start = "hit";
    string end = "cog";
    auto res = Solution().findLadders(start, end, wordList);
    for(auto& ws: res){
        for(auto&w: ws){
            cout << w << ",";
        }
        cout << endl;
    }

    return 1;
}