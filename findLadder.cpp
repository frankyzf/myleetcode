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
        auto diff = [&endWord](const string& str){
            int cnt = 0;
            for (int i = 0; i < str.length(); ++i) {
                if(str[i] != endWord[i])
                    cnt ++;
            }
            return cnt == 1;
        };


        unordered_map<string, vector<string> > ahead;
        //find candidates
        auto findcandidates = [&wordList, &ahead](string word){
            vector<string> res;
            for (int i = 0; i < word.length(); ++i) {
                char oc = word[i];
                for (int j = 0; j < 26; ++j) {
                    if('a'+ j == oc)
                        continue;
                    word.replace(i, 1, 1, (char)('a' + j));
                    if(ahead.count(word) == 0 && wordList.count(word)){
                        res.push_back(word);
                    }
                }
                word.replace(i, 1,1,oc);
            }
            return res;
        };

        vector<string> candidates {beginWord};
        bool bFound = false;

        while(candidates.size() && bFound ==false){
            vector<string> next;
            for(auto& str: candidates){
                if(diff(str)){
                    ahead[endWord].push_back(str);
                    bFound = true;
                }
                else if (!bFound){
                    auto v = findcandidates(str);
                    for(auto& w: v){
                        ahead[w].push_back(str);
                        next.push_back(w);
                    }
                }
            }
            candidates = move(next);
        }
        //backtrace
        if(bFound){
            queue<string> bt;
            bt.push(endWord);
            res.push_back(vector<string>{endWord});
            while(!bt.empty()){
                auto w = bt.front(); bt.pop();
                auto& v = ahead[w];
                auto it = find_if(res.begin(), res.end(), [&w](const vector<string>& path){return *path.rbegin() == w;});
                if(it == res.end())
                    continue;
                auto path = *it;
                if(v.size() > 0){
                    it->push_back(v[0]);
                    bt.push(v[0]);
                    for(int i = 1; i < v.size(); ++i){
                        path.push_back(v[i]);
                        res.push_back(path);
                        bt.push(v[i]);
                        path.pop_back();
                    }
                }
            }
            for(auto& item: res)
                reverse(item.begin(), item.end());
            return res;
        }
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