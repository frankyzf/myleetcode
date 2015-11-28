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


        //find candidates
        auto findcandidates = [&wordList](const unordered_set<string> &used, string word){
            vector<string> res;
            for (int i = 0; i < word.length(); ++i) {
                char oc = word[i];
                for (int j = 0; j < 26; ++j) {
                    if('a'+ j == oc)
                        continue;
                    word.replace(i, 1, 1, (char)('a' + j));
                    if(used.count(word) == 0  && wordList.count(word) ){
                        res.push_back(word);
                    }
                }
                word.replace(i, 1,1,oc);
            }
            return res;
        };
        auto diff = [&endWord](const string& str){
            int cnt = 0;
            for (int i = 0; i < str.length(); ++i) {
                if(str[i] != endWord[i])
                    cnt ++;
            }
            return cnt == 1;
        };

        unordered_set<string> visited;

        function<bool(unordered_map<string, vector<vector<string>>>&)> f =
                [&f, &wordList, &endWord,findcandidates, &res, &diff, &visited]
                        (unordered_map<string, vector<vector<string>>>& candidates ){
                    if(candidates.size() == 0)
                        return false;
            unordered_map<string, vector<vector<string>> > mcan;
            bool bFound = false;
            for(auto it = candidates.begin(); it != candidates.end(); ++it){
                visited.insert(it->first);
                if(diff(it->first) ){
                    for(auto& path: it->second){
                        path.push_back(it->first);
                        res.push_back(move(path));
                    }
                    bFound = true;
                }
                else{
                    auto cc = findcandidates(visited, it->first);
                    for(auto& item:cc){
                        for(auto& path: it->second){
                            path.push_back(it->first);
                            mcan[item].push_back(path);
                            path.pop_back();
                        }
                    }
                }
            }

            if(bFound)
                return true;
            else{
                return f(mcan);
            }
        };

        visited.insert(beginWord);
        unordered_map<string, vector<vector<string>>> path{{beginWord,{{}}}};
        f(path);
        for(auto& item: res)
            item.push_back(endWord);
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